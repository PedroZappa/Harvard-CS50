#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKYELLOW "\e[38;2;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define RED "\e[38;2;255;0;0m"
#define GREEN "\e[38;2;0;255;0m"
#define YELLOW "\e[38;2;255;255;0m"
#define CYAN "\e[38;2;0;255;255m"
#define RESET "\e[0m"

#define BLOCK_SIZE 512

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        // Print error message if the program is not given the correct # of args
        printf(RED "Usage: " RESET GREEN "./recover IMAGE\n" RESET);
        return 1;
    }

    // Open the forensic image
    char *file = argv[1]; // get file name from args
    FILE *raw_file = fopen(file, "r");
    if (raw_file == NULL)
    {
        // Print an error messsage to standard error if imagecannot be opened.
        printf(RED "Could not open %s.\n" RESET, file);
        return 2;
    }
    
    // Initialize variables
    bool found_jpg = false; // Flag to keep track of whether a JPEG has been found
    int jpg_count = 0; // Counter for the number of JPEGs found
    BYTE buffer[BLOCK_SIZE]; // Buffer to store a block of data from the forensic image
    char jpg_name[8]; // Array to store the filename of the current JPEG
    FILE *outptr = NULL; // Pointer to the current JPEG file

    // Read the forensic image file black by block
    while (fread(buffer, BLOCK_SIZE, 1, raw_file) == 1)
    {
        // Check if this block marks the start of a new JPEG
        // ( the first three bytes of JPEGs are 0xff 0xd8 0xff )
        // ( The fourth byte, meanwhile, is either 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, or 0xef )
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Check if jpg file is already open from prev iteration
            if (found_jpg)
            {
                // Close the previous JPEG file
                fclose(outptr);
            }
            else 
            {
                found_jpg = true;
            }
            // Open a new JPEG file
            sprintf(jpg_name, "%03d.jpg", jpg_count); // Generate the filename for new JPEG based on jpg_count
            outptr = fopen(jpg_name, "w"); // Open a new JPEG image file with the generated filename
            if (outptr == NULL)
            {
                // Print error if the new JPEG image file cannot be created
                fclose(raw_file);
                printf(RED "Could not create %s.\n" RESET, jpg_name);
                return 3;
            }
            jpg_count++; // Increment the jpg_count variable
        }
        // Write the current block to the current JPEG file, if one is open
        if (found_jpg)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outptr);
        }
    }
    // close the forensic image file and the last JPEG file, if one was open
    fclose(raw_file);
    // Close the last JPEG outptr file
    if (found_jpg)
    {
        fclose(outptr);
    }
    // Print REcovey Stats
    printf("Recovered" GREEN " %i " RESET YELLOW "JPEGs " RESET "from " RED "%s\n" RESET, jpg_count, file);
    // Exit the program: 
    return 0;
}