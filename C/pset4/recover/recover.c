#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        // Print error message if the program is not given the correct # of args
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open the forensic image
    char *file = argv[1]; // get file name from args
    FILE *raw_file = fopen(file, "r");
    if (raw_file == NULL)
    {
        // Print an error messsage to standard error if imagecannot be opened.
        printf("Could not open %s.\n", file);
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
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the previous JPEG file, if one was open
            if (found_jpg)
            {
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
                printf("Could not create %s.\n", jpg_name);
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
    if (found_jpg)
    {
        fclose(outptr);
    }
    // Exit the program: 
    return 0;
}