#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

// Function Prototypes
int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s", infile);
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header_buffer;
    fread(&header_buffer, sizeof(WAVHEADER), 1, inptr);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header_buffer) != 0)
    {
        printf("Not A .wav file\n");
        return 1;
    }
    else
    {
        printf("Valid .wav file\n");

        // Open output file for writing
        // TODO #5
        char *outfile = argv[2];
        FILE *outptr = fopen(outfile, "wb");
        if (outptr == NULL)
        {
            printf("Could not open %s\n", outfile);
            return 1;
        }

        // Write header to file
        // TODO #6
        fwrite(&header_buffer, sizeof(WAVHEADER), 1, outptr);

        // Use get_block_size to calculate size of block
        // TODO #7
        int size = get_block_size(header_buffer);

        // Write reversed audio to file
        // TODO #8
        // if fseek() finds end pointer
        if (fseek(inptr, size, SEEK_END))
        {
            // Handle error
            return 1;
        }
        // Declare buffer
        BYTE rev_audio[size];
        // while there are samples to be read
        while (ftell(inptr) - size > sizeof(header_buffer))
        {
            // From current (end), Read data in reverse, 2 samples at a time
            if (fseek(inptr, -2 * size, SEEK_CUR))
            {
                return 1;
            }
            // Read samples from inptr
            fread(rev_audio, size, 1, inptr);
            // Write samples to outptr
            fwrite(rev_audio, size, 1, outptr);
        }
        // Close files
        fclose(inptr);
        fclose(outptr);
    }
}

int check_format(WAVHEADER header)
{
    // TODO #4
    // Expected str for comparison
    char *wave = "WAVE";
    BYTE *format_byte = header.format;
    char *format = (char *) format_byte;
    printf("format: %s\n", format);
    if (strcmp(wave, format))
    {
        return 0;
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int size = header.numChannels * header.bitsPerSample / 8;
    return size;
}