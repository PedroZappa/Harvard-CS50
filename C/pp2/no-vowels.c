// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string replace(string input);
char isUppertoUpper(char letter);

int main(int argc, string argv[])
{
    // Accepts only one arg (word to convert)
    // if more or less that 1 arg, print error & return 1
    if (argc == 1)
    {
        printf("No arguments given.\nUsage: ./no-vowels <string>\nRun me baby one more time!");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Too many arguments.\nUsage: ./no-vowels <string>\nRun me baby one more time!");
        return 1;
    }

    // Store input string
    string input = argv[1];
    // Replace vowels
    string output = replace(input);

    // print converted word followed by \n
    printf("%s\n", output);

    return 0;
}

// Replace vowels with numbers
// a => 6 && e => 3 && i => 1 && o => 0
string replace(string input)
{   
    // Loop through the elements of the string
    for (int letter = 0, n = strlen(input); letter < n; letter++)
    {
        // convert input to lowercase
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