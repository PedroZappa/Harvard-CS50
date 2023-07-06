#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score
#define EXACT 2 // == right letter, right place;
#define CLOSE 1 // == right letter, wrong place;
#define WRONG 0 // == wrong letter;

// ANSI color codes for boxed in letters
#define GREEN "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET "\e[0;39m"

// user-defined function prototypes
string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

int main(int argc, string argv[])
{
    // ensure proper usage
    // TODO #1
    if (argc != 2)
    {
        printf("Usage: ./wordle wordsize\n");
        return 1;
    }

    // ensure argv[1] is either 5, 6, 7, or 8 and store that value in wordsize instead
    // TODO #2
    int wordsize = atoi(argv[1]);
    if (wordsize < 5 || wordsize > 8)
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8.\n");
        return 1;
    }

    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        //  Make sure file is not empty
        if (fscanf(wordlist, "%s", options[i]) != 1)
        {
            printf("Error reading file %s.\n", wl_filename);
        }
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];

    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN "This is WORDLE50" RESET "\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // set all elements of status array initially to 0, aka WRONG
        // TODO #4
        for (int j = 0; j < wordsize; j++)
        {
            status[j] = WRONG;
        }

        // Calculate score for the guess
        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);

        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    // Print the game's result
    // TODO #7

    // that's all folks!
    return 0;
}

string get_guess(int wordsize)
{
    string guess = "";
    int len;
    // ensure users actually provide a guess that is the correct length
    // TODO #3

    // if user guess length != wordsize, re-prompt
    do
    {
        guess = get_string("Input a %i-letter word: ", wordsize);
        len = strlen(guess);
        // if (len != wordsize)
        // {
        //     printf("Guess must be %i characters long.\n", wordsize);
        // }
    }
    while (len != wordsize);

    // convert to lowercase
    for (int i = 0; i < wordsize; i++)
    {
        guess[i] = tolower(guess[i]);
    }

    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    int score = 0;

    // compare guess to choice and score points as appropriate, storing points in status
    // TODO #5

    // HINTS
    // iterate over each letter of the guess
    for (int i = 0; i < wordsize; i++)
    {
        // iterate over each letter of the choice
        for (int j = 0; j < wordsize; j++)
        {
            // compare the current guess letter to the current choice letter
            if (guess[i] == choice[j])
            {
                // if they're the same position in the word, score EXACT points (green) and break so you don't compare that letter
                // further
                if (i == j)
                {
                    score += EXACT;
                    status[i] = EXACT;
                    break;
                }
                // if it's in the word, but not the right spot, score CLOSE point (yellow)
                else if (status[i] != EXACT) // make sure not to override EXACT score
                {
                    score += CLOSE;
                    status[i] = CLOSE;
                }
            }
        }
    }

    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    // print word character-for-character with correct color coding, then reset terminal font to normal
    // TODO #6

    // Loop through each letter of the guess
    for (int i = 0; i < wordsize; i++)
    {
        // if the state is EXACT, print green
        if (status[i] == EXACT)
        {
            printf(GREEN "%c" RESET, guess[i]);
        }
        // if the state is CLOSE, print yellow
        else if (status[i] == CLOSE)
        {
            printf(YELLOW "%c" RESET, guess[i]);
        }
        // else print red
        else
        {
            printf(RED "%c" RESET, guess[i]);
        }
    }

    printf("\n");
    return;
}
