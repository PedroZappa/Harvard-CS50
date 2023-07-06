#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ANSI escape sequences to color output
#define BLACKBRIGHT "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define RESET "\e[0;39m"

#define MAX_LEN 100

// Declare function prototypes
bool verify_key(char* s);

int main(int argc, char* argv[])
{
    // Check commandline args
    if (argc != 2 || !verify_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Get user input key
    int len = strlen(argv[1]);
    char key[len];
    for (int i = 0; i < len; i++)
    {
        // Convert each char of key to uppercase
        key[i] = toupper(argv[1][i]);
    }

    // Get user input plaintext
    char* plaintext = malloc(MAX_LEN);
    printf("plaintext: ");
    if (!fgets(plaintext, MAX_LEN, stdin))
    {
        // Free memory
        free(plaintext);
        return 1;
    }

    // Print Cyphertext
    printf(BLACKBRIGHT "ciphertext: " RESET);

    // Loop through chars of plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Check if char is a letter
        if (isalpha(plaintext[i]))
        {
            // Check char case
            if (isupper(plaintext[i]))
            {
                // Subtract 'A' (65) from char to convert it to lowercase
                printf("%c", toupper(key[plaintext[i] - 'A']));
            }
            else
            {
                // Subtract 'a' (97) from char to convert it to lowercase
                printf("%c", tolower(key[plaintext[i] - 'a']));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

    // Free memory
    free(plaintext);

    return 0;
}

bool verify_key(char* key)
{
    // Check if len is alpohabet's length
    int len = strlen(key);
    if (len != 26)
    {
        printf("Key must be 26 characters long\n");
        return false;
    }

    // Check if all 26 chars are alphabetic
    int freq[26] = {0}; // Init all 26 elements to 0
    for (int i = 0; i < len; i++)
    {
        // Check if char is alphabetic
        if (!isalpha(key[i]))
        {
            printf("Key must contain only alphabetic characters\n");
            return false;
        }

        // Get ASCII value of current letter
        int index = toupper(key[i]) - 'A';
        // Check if letter is already in freq
        if (freq[index] > 0)
            return false;

        freq[index]++;
    }

    return true;
}