// Modifies the volume of an audio file
/*
    WAV Header (44-bytes)
        (includes: file size, # samples/second, sample size)
        We can treat each byte of a WAV file’s header as a uint8_t value.
    Audio Samples
        each 2-byte (16-bit) int
        We can treat each sample of audio in a WAV file as an int16_t value.

    Args:
        input: filename
        output: filename
        factor: scale amount (float)

*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define RESET "\e[0;39m"

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
// Each HEADER BYTE is a uint8_t
typedef uint8_t BYTE;
// Each SAMPLE is an int16_t
typedef int16_t SAMPLE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf(RED "Usage: " RESET GREEN "./volume input.wav output.wav factor\n" RESET);
        return 1;
    }

    // Open input and output files
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf(RED "Could not open file.\n" RESET);
        return 1;
    }
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf(RED "Could not open file.\n" RESET);
        return 1;
    }

    // Calculate volume scaling factor
    float factor = atof(argv[3]);

    // TODO: Copy wav header (44-bytes) from input file to output file
    BYTE header_buffer[HEADER_SIZE];
    // Read input Header into buffer
    fread(&header_buffer, HEADER_SIZE, 1, input);
    // Write buffer into output file
    fwrite(&header_buffer, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    SAMPLE sample_buffer;
    // Read from input into buffer 1 sample at a time
    while (fread(&sample_buffer, sizeof(SAMPLE), 1, input) == 1)
    {
        // Multiply sample by volume factor
        sample_buffer *= factor;
        // Write new sample into output file
        fwrite(&sample_buffer, sizeof(SAMPLE), 1, output);
    }

    // Success
    printf(GREEN "Successfully modified audio file's volume by factor of %.2f.\n" RESET, factor);

    // Close files
    fclose(input);
    fclose(output);
}