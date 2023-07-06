#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Declare function prototypes
bool verify_key(string s);

int main(int argc, string argv[])
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
    string plaintext = get_string("plaintext: ");

    // Print Cyphertext
    printf("ciphertext: ");

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

    return 0;
}

bool verify_key(string key)
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