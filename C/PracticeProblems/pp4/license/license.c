#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read each element into
    char buffer[7];

    // Create array to store plate numbers
    // Stores 8 plates with 7 elements == plates[plate][element]
    char plates[8][7];

    // Pointer to external file
    FILE *infile = fopen(argv[1], "r");

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

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }
}
