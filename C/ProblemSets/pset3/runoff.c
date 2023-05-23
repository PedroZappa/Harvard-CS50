/*
Instant Runoff Voting System.

    voters rank as many candidates as they wish.
    If any candidate has (more than 50%) of the first preference votes
        That candidate is declared the winner of the election.
    If NO candidate has more than 50% of the votes
        candidate with less votes is eliminated
    Re-Run election
*/
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
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
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    // Set initial name and votes for candidates[i]
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

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
bool vote(int voter, int rank, string name)
{
    /*
        for i from 0 to n-1
            if name == candidates[i].name
                preferences[voter][rank] = name
                return true
        return false
    */
    // Loop through candidates[] // i = candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // if strcmp() returns 0 means strings are equal
        if (strcmp(candidates[i].name, name) == 0)
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
void tabulate(void)
{
    /*
        for i (voter) from 0 to n-1
            for j (rank) from 0 to n-1
                if candidate[preference[i][j]].eliminated == false
                    candidates[preference[i][j]].votes++
                    break;
        return
    */
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
    return;
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
            printf("%s\n", candidates[i].name);
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