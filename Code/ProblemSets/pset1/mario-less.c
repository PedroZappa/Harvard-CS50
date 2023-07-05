#include <ctype.h>
#include <stdio.h>

// ANSI escape sequences to color output
const char *bgWhite = "\033[47m";
const char *blackBright = "\033[90m";
const char *black = "\033[30m";
const char *cyan = "\033[36m";
const char *green = "\033[32m";
const char *red = "\033[31m";
const char *magenta = "\033[35m";
const char *reset = "\033[0m";

int main(void)
{
    int height;
    // Prompt user for height
    // Reprompt if height < 1 or > 8 || not an integer
    do
    {
        printf("%sHeight: %s", blackBright, reset);
        scanf("%d", &height);
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
        // Print Hashes
        for (int hash = 1; hash <= row; hash++)
        {
            printf("%s#%s", red, reset);
        }
        printf("\n");
    }

    return 0;
}