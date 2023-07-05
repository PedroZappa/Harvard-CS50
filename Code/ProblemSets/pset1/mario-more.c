#include <ctype.h>
#include <stdio.h>

// ANSI escape sequences to color output
const char *blackBright = "\033[90m";
const char *green = "\033[32m";
const char *red = "\033[31m";
const char *reset = "\033[0m";

int main(void)
{
    int height;
    // Prompt user for height
    // Reprompt if height < 1 or > 8 || not an integer
    do
    {
        printf("%sHeight: %s", blackBright, reset);
        if (scanf("%d", &height) != 1)
        {
            // If scanf() couldn't scan an integer, consume invalid input and continue prompting
            int c;
            while ((c = getchar()) != EOF && c != '\n') 
            {
                // Print error message
                printf(
                    "%sError%s, input a valid %sinteger%s.\n",
                    red, reset, green, reset
                );
            }
        }
    }
    while (height < 1 || height > 8 || isdigit(height));

    // Print Ascending # Pyramid
    for (int row = 1; row <= height; row++)
    {
        // Print white spaces
        for (int space = 1; space <= height - row; space++)
        {
            printf(" ");
        }
        
        // Print Left Hashes
        for (int hash = 1; hash <= row; hash++)
        {
            printf("%s#%s", red, reset);
        }

        // Print Middle space
        printf("  ");

        // Print Right Hashes
        for (int hash = 1; hash <= row; hash++)
        {
            printf("%s#%s", red, reset);
        }

        // Line break
        printf("\n");
    }

    return 0;
}