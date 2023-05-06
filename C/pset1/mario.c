#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int height;
    // Prompt user for height
    // Reprompt if height < 1 or > 8 || not an integer
    do
    {
        height = get_int("Height: ");
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
            printf("#");
        }
        printf("\n");
    }

    // DEBUGGER
    // printf("%i\n", height);
    // =====
    return 0;
}