#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check argc for the existence of argv[1]
    if (argc < 2)
    {
        printf("\nNot enough args", argc);
        return 1;
    }
    else if (argc > 2)
    {
        printf("\nToo many args", argc);
        return 1;
    }
    else if (argc == 2)
    {
        // Decription Key = argv[1]
        int key = atoi(argv[1]);
        // If argc is NOT 2
        if (argc != 2 || argv[1] == NULL)
        {
            printf("\nUsage: ./caesar key\n");
            return 1;
        }
        else
        {
            // Check if key is a positive int
            while (key < 0)
            {
                printf("Please enter a positive integer.\n");
                return 1;
            }

            for (int i = 0, len = strlen(&argv[1][i]); i < len; i++)
            {
                // If argv[1][i] is NOT a digit
                if (!isdigit(argv[1][i]))
                {
                    printf("\nKey not a digit!\nUsage: ./caesar key\n");
                    return 1;
                }
            }
        }

        // Get user string
        char *plaintext = get_string("plaintext: ");

        // Encrypting user string
        printf("ciphertext: ");
        // loop through chars string
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // Check if char == letter
            if (isalpha(plaintext[i]))
            {
                // Check if char is uppercase
                if (isupper(plaintext[i]))
                {
                    // Convert uppercase letter to number then cipher it
                    char cipher_num_upper = (plaintext[i] - 'A' + key) % 26 + 'A';
                    printf("%c", cipher_num_upper);

                    // Print the ciphered number as a letter

                }
                // Check if char is lowercase
                else if (islower(plaintext[i]))
                {
                    // Convert lowercase letter to number then cipher it
                    char cipher_num_lower = (plaintext[i] - 'a' + key) % 26 + 'a';
                    printf("%c", cipher_num_lower);
                }
            }
            else
            {
                // If char is not a letter, print it as is
                printf("%c", plaintext[i]);
            }

        }
        printf("\n");
        return 0;

        // DEBUGGER
        // printf("\n\nDEBUG:\nKey = %s\n", argv[1]);
    }
}