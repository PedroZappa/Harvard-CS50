/* Plurality Vote */
#include <ctype.h> // isdigit()
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> // strcspn()
#include <strings.h>

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define RESET "\e[0;39m"

// Max number of candidates
#define MAX 9
#define MAX_LEN 30

// Candidates have name and vote count
typedef struct
{
    char *name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(char *name);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf(BLACKBRIGHT "Usage: " RESET RED "plurality [candidate ...]\n" RESET);
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf(RED "Maximum number of candidates is %i\n" RESET, MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Prompt user for # of voters
    char *end;
    char voter_count_str[MAX_LEN];
    long voter_count_long;
    do
    {
        printf(BLACKBRIGHT "Number of voters: " RESET);
        fgets(voter_count_str, MAX_LEN, stdin);
        // Remove newline character from voter_count_str
        voter_count_str[strcspn(voter_count_str, "\n")] = '\0';
        // Convert voter_count_str to long int
        voter_count_long = strtol(voter_count_str, &end, 10);
    } 
    while (end == voter_count_str || *end != '\0' || voter_count_long < 0);

    // Loop over all voters
    int voter_count = (int) voter_count_long; // type cast long to int
    for (int i = 0; i < voter_count; i++)
    {
        // Get current voter's vote
        int current_vote = i + 1;
        char name[MAX_LEN];
        bool valid_vote = false;
        while (!valid_vote)
        {
            printf(CYAN "Vote %d: " RESET, current_vote);
            fgets(name, MAX_LEN, stdin);

            // Remove newline character from name
            name[strcspn(name, "\n")] = '\0';

            // Check for invalid vote
            if (!vote(name))
            {
                printf(RED "Invalid vote.\n" RESET);
            }
            else
            {
                valid_vote = true;
            }
        }
    }
    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(char *name)
{
    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // compare input name and candidates[i].name
        if (strcasecmp(name, candidates[i].name) == 0)
        {
            // If candidate match found
            candidates[i].votes++;
            return true;
        }       
    }
    return false;
}

// Print the results of the election
void print_winner(void)
{
    int max_votes = 0;
    int num_winners = 0;
    char* winners[MAX];
    
    // Loop through the candidates to find the highest number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if the current candidate has more votes than the current maximum
        if (candidates[i].votes > max_votes)
        {
            // If so, update the maximum number of votes
            max_votes = candidates[i].votes;
            num_winners++;
            winners[0] = candidates[i].name;
        }
        else if (candidates[i].votes == max_votes)
        {
            // If there is a tie, add the candidate's name to the winners array
            winners[num_winners] = candidates[i].name;
            num_winners++;
        }
    }

    // If there is only one winner, print the winner's name
    if (num_winners == 1)
    {
        printf(YELLOW "Winner: " RESET GREEN "%s\n" RESET, winners[0]);
    }
    // If there are multiple winners, print them as tied candidates
    else if (num_winners > 1)
    {
        printf(YELLOW "Tied: " RESET);
        for (int i = 0; i < num_winners; i++)
        {
            printf(GREEN "%s" RESET, winners[i]);
            if (i < num_winners - 1)
            {
                printf(BLACKBRIGHT " & " RESET);
            }
        }
        printf("\n");
    }
    return;
}