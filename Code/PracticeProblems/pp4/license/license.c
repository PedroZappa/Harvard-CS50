#include <stdio.h>

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKYELLOW "\e[38;2;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define RED "\e[38;2;255;0;0m"
#define GREEN "\e[38;2;0;255;0m"
#define YELLOW "\e[38;2;255;255;0m"
#define CYAN "\e[38;2;0;255;255m"
#define RESET "\e[0m"

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf(RED "Usage: " RESET GREEN "./read infile\n" RESET);
        return 1;
    }

    // Create buffer to read each element into
    char buffer[7];

    // Create array to store plate numbers
    // Stores 8 plates with 7 elements == plates[plate][element]
    char plates[8][7];

    // Pointer to external file
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf(RED "Could not open file.\n" RESET);
        return 1;
    }

    // to store index of each plates[] element
    int idx = 0;

    // Read each element into buffer
    // Loop through plates
    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        // Loop through each element of each plates[plate][element]
        for (int i = 0; i < 7; i++)
        {
            // Save plate number in array
            plates[idx][i] = buffer[i];
        }
        idx++;
    }

    // Titles
    printf(BLACKWHITE "Plates in " RESET BLACKYELLOW "%s" RESET BLACKWHITE " file:" RESET "\n", argv[1]);
    // Print each plate
    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }
}
