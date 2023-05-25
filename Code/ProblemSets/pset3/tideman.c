#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

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
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool cycle_check(int start, int end);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate is valid
        if (strcmp(candidates[i], name) == 0)
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
                // Sawp pairs if victory strength of 'j' is less than the victory strength of `j+1`
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
                    printf("%s\n", candidates[i]);
                }
            }
        }
    }
    return;
}