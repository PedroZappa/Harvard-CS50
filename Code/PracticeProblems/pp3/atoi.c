#include <ctype.h> // isspace() isdigit()
#include <math.h>
#include <stdio.h> // printf() fgets()
#include <stdlib.h> // malloc() free()
#include <string.h> // strlen() strcspn() memmove()

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define RED "\e[31m"
#define RESET "\e[0;39m"

const int MAX_LEN = 100;

int convert(char *input);

int main(void)
{
    // Get user input
    char *input = malloc(MAX_LEN);
    do
    {
        printf(BLACKBRIGHT "Enter a positive integer: " RESET);
        fgets(input, MAX_LEN, stdin);
        // Reprompt if input is empty
    } while (input[0] == '\n');
    
    // Check if input is empty
    if (strlen(input) == 0)
    {
        printf(RED "No Input!\n" RESET);

        // Free allocated memory
        free(input);

        return 1;
    }
    
    // Remove newline
    input[strcspn(input, "\n")] = 0;

    // Strip leading whitespace
    while (isspace((unsigned char)input[0]))
    {
        memmove(input, input + 1, strlen(input));
    }

    // Strip trailing whitespace
    size_t input_len = strlen(input);
    while (input_len > 0 && isspace((unsigned char)input[input_len - 1]))
    {
        input[input_len - 1] = '\0';
        input_len--;
    }

    // Check if string contains only digits
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf(RED "Invalid Input!\n" RESET);

            // Free allocated memory
        free(input);
            return 2;
        }
    }

    // Convert string to int
    printf(GREEN "%i\n" RESET, convert(input));

    // Free allocated memory
    free(input);
}

int convert(char *input)
{
    int input_len = strlen(input);

    // Base case when creating a recursive function.
    if (input_len == 1)
    {
        // return the numeric value of the single character in the input string by subtracting the ASCII value of '0' from it
        return input[0] - '0';
    }

    // Getting the index of the last char in the string (the char before the \0).
    char last_digit = input[input_len - 1];

    // Convert this char into its numeric value.
    int converted_digit = last_digit - '0';

    // Remove the last char from the string by moving the null terminator one position to the left.
    input[input_len - 1] = '\0';

    // Return this value plus 10 times the integer value of the new shortened string.
    return converted_digit + 10 * convert(input);
}