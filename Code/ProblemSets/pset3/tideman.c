// #include <cs50.h>
#include <ctype.h> // isspace()
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define RESET "\e[0;39m"

// Max number of candidates
#define MAX 5
#define MAX_LEN 30


// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
char *candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, char *name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool cycle_check(int start, int end);
void lock_pairs(void);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Title
    printf(BLACKWHITE "Tideman Election!" RESET "\n");

    // Check for invalid usage
    if (argc < 2)
    {
        printf(BLACKBRIGHT "Usage: " RESET RED "./tideman [candidate ...]\n" RESET);
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    // Handle too many candidates
    if (candidate_count > MAX)
    {
        printf(BLACKBRIGHT "Maximum number of candidates is " RESET BLACKBRIGHT " %i\n" RESET, MAX);
        return 2;
    }
    // Print Candidates
    printf(GREEN "Candidates: " RESET); 

    // Add args to array of candidates 
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
        printf(YELLOW "%s " RESET, candidates[i]);
        if (i != candidate_count - 1)
        {
            printf(BLACKBRIGHT "|| " RESET);
        }
    }
    printf("\n");

    // Loop through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Loop through every other candidate
        for (int j = 0; j < candidate_count; j++)
        {
            // Clear graph of locked in pairs
            locked[i][j] = false;
        }
    }

    // Get number of voters, reprompt if invalid
    char voter_count_str[MAX_LEN];
    long voter_count_long;
    char *end;
    do
    {
        printf("Number of voters: ");
        fgets(voter_count_str, MAX_LEN, stdin);
        // Remove newline character from voter_count_str
        voter_count_str[strcspn(voter_count_str, "\n")] = '\0';
        // Convert voter_count_str to long int
        voter_count_long = strtol(voter_count_str, &end, 10);

    } 
    while (*end != '\0' || voter_count_long < 0);
    // type cast long to int
    int voter_count = (int) voter_count_long; 

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Print Header
        printf(BLACKWHITE "[ Voter %i ]" RESET "\n", i + 1);
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char *name = malloc(MAX_LEN);
            if (name == NULL)
            {
                printf(RED "Insufficient memory.\n" RESET);
                return 1;
            }
            // Query current rank
            printf(CYAN "Rank %i: " RESET, j + 1);
            fgets(name, MAX_LEN, stdin);
            // Remove newline from name
            name[strcspn(name, "\n")] = '\0';
            // Strip trailing whitespaces
            char *end = name + strlen(name) - 1; // Get the end of the string
            while (end >= name && isspace((unsigned char)*end))
            {
                *end = '\0';
                end--;
            }
            // Strip leading whitespaces
            while (isspace((unsigned char)name[0]))
            {
                memmove(name, name + 1, strlen(name));
            }

            if (!vote(j, name, ranks))
            {
                printf(RED "Invalid vote.\n" RESET);
                return 3;
            }
        }

        record_preferences(ranks);
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, char *name, int ranks[])
{
    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate is valid
        if (strcasecmp(candidates[i], name) == 0)
        {
            // Add rank to ranks[]
            ranks[rank] = i;
            return true;
        }
    }
    // If no match is found
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // Loop through all pairs of candidates (using 2 for loops)
    for (int i = 0; i < candidate_count; i++)
    {
        // starts at i + 1 to avoid counting pairs twice
        for (int j = i + 1; j < candidate_count; j++)
        {
            // update preferences[][]
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int index = 0;
    // Loop through all pairs of candidates (using 2 for loops)
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // Check who has more votes (i or j)
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[index].winner = i;
                pairs[index].loser = j;
                index++;
            }
        }
    }
    pair_count = index;
    return;
}

void sort_pairs(void)
{
    // Bubble Sort ( Decreasing order )
    // Loop over pairs[] (except last pair)
    for (int i = 0; i < pair_count - 1;  i++)
    {
        // Compare adjacent pairs, check if they are in the correct order
        // By using pair_count - j - 1 in the internal loop, we "shorten" the array that needs to be compared in each iteration.
        for (int j = 0; j < pair_count - j - 1; j++)
        {
            // Use the `preferences[][]` to get the number of voters who prefer one candidate over the other
            // Compare the victory strength of the current pair `j` to the victory strength of the next pair `j+1`
            if (preferences[pairs[j].winner][pairs[j].loser] < preferences[pairs[j + 1].winner][pairs[j + 1].loser])
            {
                // if victory strength of 'j' is less than the victory strength of `j+1` swap them
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
    return;
}

// Checks if there is a cycle in the directed graph represented by the locked[][] matrix.
// It takes two parameters: the start and end vertices (candidates) of the edge being considered.
bool cycle_check(int start, int end)
{
    if (start == end)
    {
        // cycle found
        return true;
    }
    // loop through all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If there is an edge from the end vertex to vertex i
        if (locked[end][i])
        {
            // recursively call cycle_check()
            if (cycle_check(start, i))
            {
                // cycle found
                return true;
            }
        }
    }
    // no cycle found
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Loop through pairs[]
    for (int i = 0; i < pair_count; i++)
    {
        if (!cycle_check(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // Loop through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        int false_count = 0;
        // Loop through each candidate's col in the locked[]
        for (int j = 0; j < candidate_count; j++)
        {
            // If there is a false value in the column, increment false_count
            if (locked[j][i] == false)
            {
                false_count++;
                // If whole col is false, candidate is source of graph
                if (false_count == candidate_count)
                {
                    printf(RED "%s" RESET BLACKWHITE " wins! " RESET "\n", candidates[i]);
                }
            }
        }
    }
    return;
}