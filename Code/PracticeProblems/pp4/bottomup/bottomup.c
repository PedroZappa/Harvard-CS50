// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define RESET "\e[0;39m"

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf(RED "Usage: " RESET GREEN "./bottomup infile outfile\n" RESET);
        return 1;
    }

    // Remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf(RED "Could not open " RESET BLACKBRIGHT" %s." RESET "\n", infile);
        return 2;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf(BLACKBRIGHT "Could not create" RESET RED" %s.\n" RESET, outfile);
        return 3;
    }

    // Read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        // Close inptr & outptr
        fclose(outptr);
        fclose(inptr);
        printf(RED "Unsupported file format.\n" RESET);
        return 4;
    }

    // VErtically flip .bpm to bottomup
    bi.biHeight = bi.biHeight * (-1);

    // Write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    // Write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // BMP images require each scanline to be a multiple of 4 bytes, so padding is added as needed.
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // Iterate over infile's scanlines (rows)
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Iterate over pixels in scanline (cols)
        for (int j = 0; j < bi.biWidth; j++)
        {
            // Temporary storage
            RGBTRIPLE triple;
            // Read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            // Write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }
        // Ensure that the output file has the same padding as the input file.
        // Skip over inptr padding, if any
        fseek(inptr, padding, SEEK_CUR);
        // Then add it back to outptr (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            // write a single NULL byte (0x00) to the output file
            fputc(0x00, outptr);
        }
    }

    // Close infile
    fclose(inptr);
    // Close outfile
    fclose(outptr);

    // Success
    printf(GREEN "Image Inverted Vertically!\n" RESET);
    return 0;
}
