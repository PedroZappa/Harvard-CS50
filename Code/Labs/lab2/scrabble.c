#include <ctype.h>
#include <stdio.h>
#include <string.h>

// ANSI escape sequences to color output
const char *blackBright = "\033[90m";
const char *cyan = "\033[36m";
const char *green = "\033[32m";
const char *red = "\033[31m";
const char *yellow = "\033[33m";
const char *reset = "\033[0m";

#define MAX_SIZE 30

// Points assigned to each letter of the alphabet [ POINTS[25] ]
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word);

int main(void)
{
    // Get input words from both players
    printf("%sInput Word for each Player%s:\n", cyan, reset);

    char word1[MAX_SIZE]; 
    printf("%sPlayer 1%s: ", blackBright, reset);
    fgets(word1, MAX_SIZE, stdin);

    char word2[MAX_SIZE];
    printf("%sPlayer 2%s: ", blackBright, reset);
    fgets(word2, MAX_SIZE, stdin);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    // Get input words from both players
    printf("%sScrabble Results%s:\n", cyan, reset);

    if (score1 > score2)
    {
        // Player 1 wins
        printf(
            "%sPlayer 1%s %swins%s with: %d\n", 
            blackBright, reset, green, reset, score1
        );
        printf(
            "%sPlayer 2%s %slooses%s with: %d\n", 
            blackBright, reset, red, reset, score2
        );
    }
    else if (score1 < score2)
    {
        // Player 2 wins
        printf(
            "%sPlayer 2%s %swins%s with: %d\n",
            blackBright, reset, green, reset, score2
        );
        printf(
            "%sPlayer 1%s %slooses%s with: %d\n", 
            blackBright, reset, red, reset, score1
        );
    }
    else
    {
        // Tie
        printf(
            "\n%sIt's a tie with%s %s%d%s %spoints!%s\n",
            yellow, reset, red, score1, reset, yellow, reset
        );
    }
}

int compute_score(char *word)
{
    // Score Tracker
    int score = 0;

 // Compute score for each character
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            // - 'A' == -65
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            // - 'a' == -97
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
