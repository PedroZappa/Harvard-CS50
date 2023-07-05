// Write a function to replace vowels with numbers
// Get practice with char*s
// Get practice with command line
// Get practice with switch

#include <ctype.h>
#include <stdio.h>
#include <string.h>

// ANSI escape sequences to color output
const char *blackBright = "\033[90m";
const char *cyan = "\033[36m";
const char *green = "\033[32m";
const char *red = "\033[31m";
const char *yellow = "\033[33m";
const char *magenta = "\033[35m";
const char *reset = "\033[0m";

char* replace(char* input);
char isUppertoUpper(char letter);

int main(int argc, char* argv[])
{
    // Accepts only one arg (word to convert)
    // if more or less that 1 arg, print error & return 1
    if (argc == 1)
    {
        printf(
            "%sNo arguments given.%s\n%sUsage: ./no-vowels 'string'%s\n%sRun me baby one more time!%s\n", 
            red, reset, green, reset, magenta, reset
        );
        return 1;
    }
    else if (argc > 2)
    {
        printf(
            "%sToo many arguments.%s\n%sUsage: ./no-vowels 'string'%s\n%sRun me baby one more time!%s\n",
            red, reset, green, reset, magenta, reset
        );
        return 1;
    }

    // Store input char*
    char* input = argv[1];
    // Replace vowels
    char* output = replace(input);

    // print converted word followed by \n
    printf("%s%s%s\n", green, output, reset);

    return 0;
}

// Replace vowels with numbers
// a => 6 && e => 3 && i => 1 && o => 0
char* replace(char* input)
{   
    // Loop through the elements of the char*
    for (int letter = 0, n = strlen(input); letter < n; letter++)
    {
        // convert each letter from input to lowercase
        char lowercase_letter = tolower(input[letter]);
        
        // if element is a vowel switch it with number
        switch (lowercase_letter)
        {
        case 'a':
            input[letter] = '6';
            break;
        case 'e':
            input[letter] = '3';
            break;
        case 'i':
            input[letter] = '1';
            break;
        case 'o':
            input[letter] = '0';
            break;
        default:
            isUppertoUpper(input[letter]);
            break;
        }
    }
    // return converted word
    return input;
}

char isUppertoUpper(char letter)
{
    // if letter isUppercase convert it toUpper()
    if (isupper(letter))
    {
        letter = toupper(letter);
    }
    return letter;
}