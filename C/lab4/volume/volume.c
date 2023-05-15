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

typedef uint8_t BYTE;
typedef int16_t SAMPLE;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Camculate volume scaling
    float factor = atof(argv[3]);

    // TODO: Copy header (44-bytes) from input file to output file
    BYTE header_buffer[HEADER_SIZE];
    // Read input Header into buffer
    fread(&header_buffer, HEADER_SIZE, 1, input);
    // Write buffer into output file
    fwrite(&header_buffer, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    SAMPLE sample_buffer;
    // Read sample from input into buffer
    while (fread(&sample_buffer, sizeof(SAMPLE), 1, input) == 1)
    {
        // Multiply sample by volume factor
        sample_buffer *= factor;
        // Write new sample into output file
        fwrite(&sample_buffer, sizeof(SAMPLE), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}