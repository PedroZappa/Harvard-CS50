/*
Instant Runoff Voting System.

    voters rank as many candidates as they wish.
    If any candidate has (more than 50%) of the first preference votes
        That candidate is declared the winner of the election.
    If NO candidate has more than 50% of the votes
        candidate with less votes is eliminated
    Re-Run election
*/
#include <ctype.h>  // isspace()
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // malloc()
#include <string.h>

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define RESET "\e[0;39m"

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9
#define MAX_LEN 30

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    char *name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, char *name);
int tabulate(int voter_count, int candidate_count);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[])
{
    // Titles
    printf(BLACKWHITE "Instant Runoff Election!" RESET "\n");
    // Check for invalid usage
    if (argc < 2)
    {
        printf(RED "Usage: " RESET BLACKBRIGHT "runoff [candidate ...]\n" RESET);
        return 1;
    }
    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf(BLACKBRIGHT "Maximum number of candidates is" RESET RED " %i\n" RESET, MAX_CANDIDATES);
        return 2;
    }
    // Set initial name and votes for candidates[i]
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    // Print candidates to user
    printf(CYAN "Candidates: " RESET);
    for (int i = 0; i < candidate_count; i++)
    {
        printf(YELLOW "%s " RESET, candidates[i].name);
        if (i != candidate_count - 1)
        {
            printf(BLACKBRIGHT "|| " RESET);
        }
    }
    printf("\n");
    // Get number of voters
    int voter_count;
    printf(GREEN "Number of voters: " RESET);
    if (scanf("%i", &voter_count) == 1) 
    {
        if (voter_count > MAX_VOTERS)
        {
            printf(BLACKBRIGHT "Maximum number of candidates is" RESET RED " %i\n" RESET, MAX_CANDIDATES);
            return 3;
        }
    }
    else
    {
        printf(RED "Invalid number of voters.\n" RESET);
        return 4;
    }
    // Consume the newline character
    getchar();
    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Print current voter
        printf(BLACKWHITE "[ Voter %i ]" RESET "\n", i + 1);
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char *name = malloc(sizeof(char) * MAX_LEN);
            if (name == NULL)
            {
                printf(RED "Unable to allocate memory.\n" RESET);
                return 4;
            }
            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                while (true)
                {
                    printf(BLACKBRIGHT "Rank %i: " RESET, j + 1);
                    fgets(name, sizeof(name), stdin);
                    // Remove newline from name
                    name[strcspn(name, "\n")] = '\0';
                    // Strip leading whitespaces
                    while (isspace((unsigned char)name[0]))
                    {
                        memmove(name, name + 1, strlen(name));
                    }
                    // Strip trailing whitespaces
                    char *end = name + strlen(name) - 1; // Get the end of the string
                    while (end >= name && isspace((unsigned char)*end))
                    {
                        *end = '\0';
                        end--;
                    }
                     // Exit the loop if the vote is valid
                    if (vote(i, j, name))
                    {
                        break;
                    }
                }
            }
            // Free memory
            free(name);
        }
    }
    // Keep holding runoffs until winner exists
    while (true)
    {
        // Get coter count
        int voters = voter_count;
        // Calculate votes given remaining candidates
        tabulate(voter_count, candidate_count);
        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }
        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {   
                    // Print tied candidates
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }

    return 0;
}

// Record preference if vote is valid
// Loop through candidate_count and compare candidates[i].name to name
// If name matches candidates[i].name then candidates[i].votes++
bool vote(int voter, int rank, char *name)
{
    // Loop through candidates[] // i = candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // if strcmp() returns 0 means strings are equal
        if (strcasecmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
// Update number of votes not eliminated
// Loop through i+j if NOT eliminated then add to count
int tabulate(int voter_count, int candidate_count)
{
    // Loop through voters // i = voters
    for (int i = 0; i < voter_count; i++)
    {
        // Loop through candidates // j = candidate
        for (int j = 0; j < candidate_count; j++)
        {
            // If candidate NOT eliminated
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
                break; // break out to continue tabulating
            }
        }
    }
    return 0;
}

// Print the winner of the election, if there is one
// Majority of vote = winner
// Loop through and check if votes > half the count.
// If vote count > half, then winner
bool print_winner(void)
{
    /*
        for i from 0 to n-1
            if candidate[i].votes > voter_count / 2
                print candidate[i].name
                return true
        return false
    */
    // Loop through candidates // i = candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
        {
            printf(RED "%s " RESET BLACKBRIGHT "Wins!\n" RESET, candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
// Loop through number of voters
// Loop through candidates
// if NOT eliminated and NOT lower tham min: min becomes that value
int find_min(void)
{
    /*
        for i from 0 to n-1
            if candidates[i].eliminated == false
                if candidates[i].votes < min && candidates[i].eliminated == false
                    min = candidates[i].votes
            return min_votes
    */
    int min = voter_count;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < min && candidates[i].eliminated == false)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
// If still in election votes== min
// if candidate eliminate == false
// add 1 to eliminate
// else if equal min++i
bool is_tie(int min)
{
    /*
        for i (candidates) from 0 to n-1
            if candidates[i].eliminated is false
                eliminate++
            if candidates[i].votes == min
        return false
    */
    int eliminate = 0;
    int count = 0;

    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if candidate is eliminated
        if (!candidates[i].eliminated)
        {
            eliminate++;
        }
        // Check if candidate's votes == minimum
        if (candidates[i].votes == min)
        {
            count++;
        }
    }
    if (eliminate == count)
    {
        return true;
    }

    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    /*
        for i from 0 to n-1
            if candidate[i].votes == min
                candidates[i].eliminated = true
            return 0
    */
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}