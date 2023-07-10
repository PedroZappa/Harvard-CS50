#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

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
    // ensure proper usage
    if (argc != 3)
    {
        printf(RED "Usage: " RESET GREEN "colorize infile outfile\n" RESET);
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf(RED "Could not open %s.\n" RESET, infile);
        return 4;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf(RED "Could not create %s.\n" RESET, outfile);
        return 5;
    }

    // read infile's BITMAPFILEHEADER into memory
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER into memory
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        printf(RED "Unsupported file format.\n" RESET);
        // Close inptr and outptr
        fclose(outptr);
        fclose(inptr);
        return 6;
    }

    // determine image dimensions from BITMAPINFOHEADER
    int height = abs(bi.biHeight);
    int width = bi.biWidth;

    // allocate memory for image (init to 0s)
    // image is a pointer to an array of RGBTRIPLE structs
    RGBTRIPLE (*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (image == NULL)
    {
        printf(RED "Not enough memory to store image.\n" RESET);
        // Close inptr and outptr
        fclose(outptr);
        fclose(inptr);
        return 7;
    }

    // calculate padding for scanlines based on width
    int padding =  (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;
    // iterate over infile's scanlines
    for (int i = 0; i < height; i++)
    {
        // read row into pixel array
        fread(image[i], sizeof(RGBTRIPLE), width, inptr);
        // skip over padding
        fseek(inptr, padding, SEEK_CUR);
    }

    // Colorize image
    colorize(height, width, image);

    // Save image
    // write colorized outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    // write colorized outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    // write new pixels to outfile
    for (int i = 0; i < height; i++)
    {
        // write row to outfile
        fwrite(image[i], sizeof(RGBTRIPLE), width, outptr);

        // write padding at end of row
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // Print success
    printf(GREEN "%s " RESET BLACKBRIGHT "file successfully saved.\n" RESET, argv[2]);

    // free memory for image
    free(image);
    // close infile
    fclose(inptr);
    // close outfile
    fclose(outptr);

    return 0;
}
