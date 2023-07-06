#include <ctype.h>
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

int MAX_LEN = 100;


int main(int argc, char* argv[])
{
    // check argc for the existence of argv[1]
    if (argc < 2)
    {
        printf("\n%d arg: %sNot enough args%s\n%sUsage:%s %s./caesar key%s\n", 
            argc, red, reset, yellow, reset, green, reset
        );
        return 1;
    }
    else if (argc > 2)
    {
        printf("\n%d arg: %sNot enough args%s\n%sUsage:%s %s./caesar key%s\n", 
            argc, red, reset, yellow, reset, green, reset
        );
        return 1;
    }
    else if (argc == 2)
    {
        // Decription Key = argv[1]
        int key = atoi(argv[1]);
        // If argc is NOT 2
        if (argc != 2 || argv[1] == NULL)
        {
            printf("\nUsage: %s./caesar key%s\n", yellow, reset);
            return 1;
        }
        else
        {
            // Check if key is a positive int
            while (key < 0)
            {
                printf(
                    "Please enter a %spositive integer%s.\n%sUsage:%s %s./caesar key%s\n",
                    red, reset, yellow, reset, green, reset
                );
                return 1;
            }

            for (int i = 0, len = strlen(&argv[1][i]); i < len; i++)
            {
                // If argv[1][i] is NOT a digit
                if (!isdigit(argv[1][i]))
                {
                    printf(
                        "\nKey %snot a digit%s!\n%sUsage:%s %s./caesar key%s\n",
                        red, reset, yellow, reset, green, reset
                    );
                    return 1;
                }
            }
        }

        // Get user string
        char* plaintext = malloc(MAX_LEN);
        printf("%splaintext: %s", blackBright, reset);
        if (fgets(plaintext, MAX_LEN, stdin) == NULL) 
        {
            // Handle error or EOF condition here
            printf("%sError reading input%s\n", red, reset);
            // Free memory
            free(plaintext);
            return 1;
        }

        // Encrypting user string
        printf("%sciphertext: %s", blackBright, reset);
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

        // Free memory
        free(plaintext);

        return 0;
    }
}