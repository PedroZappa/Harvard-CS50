#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ANSI escape sequences to color output
const char *blackBright = "\033[90m";
const char *cyan = "\033[36m";
const char *green = "\033[32m";
const char *red = "\033[31m";
const char *yellow = "\033[33m";
const char *magenta = "\033[35m";
const char *reset = "\033[0m";

// Declare function prototypes
int count_letters(char* text);
int count_words(char* text);
int count_sentences(char* text);
int coleman_liau(int letter_count, int word_count, int sentence_count);

int MAX_LEN = 100;


int main(void)
{
    // App title
    printf("%sText Grade Calculator%s\n", cyan, reset);
    // Get user input
    char* text = malloc(MAX_LEN);
    do
    {
        printf("%sText: %s", blackBright, reset);
        if(!fgets(text, MAX_LEN, stdin)) {
            printf("%sRead error or EOF reached.%s\n", red, reset);
            free(text); // free allocated memory
            return 1;   // Return error code
        }
        text[strcspn(text, "\n")] = 0; // remove trailing newline character

    } while (strlen(text) == 0);

    int letter_count = count_letters(text); // Count Letters
    int word_count = count_words(text); // Count words;
    int sentence_count = count_sentences(text); // Count Sentences

    // Coleman-Liau formula grading
    int cl_index = coleman_liau(letter_count, word_count, sentence_count);

    // If() to print out the correct grade
    if (cl_index >= 16)
    {
        printf("%sGrade 16+%s\n", green, reset);
    }
    else if (cl_index <= 1)
    {
        printf("%sBefore Grade 1%s\n", green, reset);
    }
    else
    {
        printf("%sGrade %i%s\n", green, cl_index, reset);
    }

    // Free allocated memory
    free(text);

    return 0;
}

// Count # of chars in a passed text
int count_letters(char* text)
{
    int letter_count = 0;
    // Loop over each element in passed text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // Force to lower case and check if alphabetic char between 'a' & 'z'
        if (tolower(text[i]) >= 'a' && tolower(text[i]) <= 'z')
        {
            letter_count++;
        }
    }
    // Return letter count
    return letter_count;
}

// Count # of words in a passed text
int count_words(char* text)
{
    int word_count = 0;
    // Loop over each element in passed text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // Check for white-space ( value 32 )
        if (text[i] == 32)
        {
            word_count++;
        }
    }
    // Return word count
    return word_count + 1; // (+1) for returning at least 1
}

// Count # of sentences in a passed text
int count_sentences(char* text)
{
    int sentence_count = 0;
    char punct[3] = {'.', '!', '?'}; // Punctuation to check for
    // Loop over each element in passed text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((text[i] == punct[0]) || (text[i] == punct[1]) || (text[i] == punct[2]))
        {
            sentence_count++;
        }
    }
    // Return sentence count
    return sentence_count == 0 ? 1 : sentence_count;
}

// Calculate Coleman-Liau Index = 0.0588 * L - 0.296 * S - 15.8
int coleman_liau(int letter_count, int word_count, int sentence_count)
{
    double L = (float) letter_count / word_count * 100; // L = letter_count / word_count * 100 [ Letters per 100 Words ]
    double S = (float) sentence_count / word_count * 100; // S = sentence_count / word_count * 100 [ Sentences per 100 Words ]

    int cl_index = round(0.0588 * L - 0.296 * S - 15.8);
    return cl_index;
}