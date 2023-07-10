#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

// ANSI color codes for boxed in letters
#define BLACKWHITE "\e[38;2;255;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKYELLOW "\e[38;2;255;255;1m\e[48;2;0;0;0;1m"
#define BLACKBRIGHT "\e[90m"
#define RED "\e[38;2;255;0;0m"
#define GREEN "\e[38;2;0;255;0m"
#define YELLOW "\e[38;2;255;255;0m"
#define CYAN "\e[38;2;0;255;255m"
#define RESET "\e[0m"

// Declare function prototypes
void debug(BITMAPFILEHEADER bf, BITMAPINFOHEADER bi);

int main(int argc, char *argv[])
{
    // Titles
    printf(BLACKYELLOW "Filtering Images" RESET "\n");
    
    // Define allowable filters
    char *filters = "bgrs";
    
    // Get filter flag and check validity
    char filter = getopt(argc, argv, filters);
    if (filter == '?')
    {
        printf(RED "Invalid filter.\n" RESET);
        return 1;
    }

    // Ensure only one filter
    if (getopt(argc, argv, filters) != -1)
    {
        printf(RED "Only " YELLOW "one" RESET RED " filter allowed.\n" RESET);
        return 2;
    }

    // Ensure proper usage
    if (argc == optind + 4)
    {
        printf(RED"Usage: " RESET GREEN "./filter [flag] infile outfile [meta]\n" RESET);
        return 3;
    }

    // Remember filenames
    char *infile = argv[optind];
    char *outfile = argv[optind + 1];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 4;
    }
    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", outfile);
        return 5;
    }

    // Read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    if (argc == optind + 3 && strcmp(argv[optind + 2], "meta") == 0)
    {
        // DEBUG
        debug(bf, bi);
    }
    
    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        printf("Unsupported file format.\n");
        return 6;
    }

    // Get image's dimensions
    int height = abs(bi.biHeight);
    int width = bi.biWidth;

    // Allocate memory for image
    RGBTRIPLE(*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (image == NULL)
    {
        printf("Not enough memory to store image.\n");
        fclose(outptr);
        fclose(inptr);
        return 7;
    }

    // Determine padding for scanlines
    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

    // Iterate over infile's scanlines
    for (int i = 0; i < height; i++)
    {
        // Read row into pixel array
        fread(image[i], sizeof(RGBTRIPLE), width, inptr);

        // Skip over padding
        fseek(inptr, padding, SEEK_CUR);
    }

    // Filter image
    char selected_filter[10] = ""; 
    switch (filter)
    {
        // Blur
        case 'b':
            blur(height, width, image);
            strcpy(selected_filter, "blur");
            break;

        // Grayscale
        case 'g':
            grayscale(height, width, image);
            strcpy(selected_filter, "grayscale");

            break;

        // Reflection
        case 'r':
            reflect(height, width, image);
            strcpy(selected_filter, "reflect");

            break;

        // Sepia
        case 's':
            sepia(height, width, image);
            strcpy(selected_filter, "sepia");
            break;
    }

    // Write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Write new pixels to outfile
    for (int i = 0; i < height; i++)
    {
        // Write row to outfile
        fwrite(image[i], sizeof(RGBTRIPLE), width, outptr);

        // Write padding at end of row
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // Print Success
    printf(CYAN "%s" RESET GREEN " file successfully " RED "%s" RESET GREEN " filtered.\n" RESET, argv[2], selected_filter);

    // Free memory for image
    free(image);

    // Close files
    fclose(inptr);
    fclose(outptr);
    return 0;
}

void debug(BITMAPFILEHEADER bf, BITMAPINFOHEADER bi)
{
    // Print Bitmap File Header
    printf(BLACKWHITE "BITMAPFILEHEADER:" RESET "\n");
    printf(BLACKBRIGHT "bfType: " RESET "%hu\n", bf.bfType);
    printf(BLACKBRIGHT "bfSize: " RESET "%u\n", bf.bfSize);
    printf(BLACKBRIGHT "bfReserved1: " RESET "%hu\n", bf.bfReserved1);
    printf(BLACKBRIGHT "bfReserved2: " RESET "%hu\n", bf.bfReserved2);
    printf(BLACKBRIGHT "bfOffBits: " RESET "%u\n", bf.bfOffBits);
    // Print Bitmap Info Header
    printf(BLACKWHITE "BITMAPINFOHEADER:" RESET "\n");
    printf(BLACKBRIGHT "biSize: " RESET "%u\n", bi.biSize);
    printf(BLACKBRIGHT "biWidth: " RESET "%d\n", bi.biWidth);
    printf(BLACKBRIGHT "biHeight: " RESET "%d\n", bi.biHeight);
    printf(BLACKBRIGHT "biPlanes: " RESET "%hu\n", bi.biPlanes);
    printf(BLACKBRIGHT "biBitCount: " RESET "%hu\n", bi.biBitCount);
    printf(BLACKBRIGHT "biCompression: " RESET "%u\n", bi.biCompression);
    printf(BLACKBRIGHT "biSizeImage: " RESET "%u\n", bi.biSizeImage);
    printf(BLACKBRIGHT "biXPelsPerMeter: " RESET "%d\n", bi.biXPelsPerMeter);
    printf(BLACKBRIGHT "biYPelsPerMeter:" RESET "%d\n", bi.biYPelsPerMeter);
    printf(BLACKBRIGHT "biClrUsed: " RESET "%u\n", bi.biClrUsed);
    printf(BLACKBRIGHT "biClrImportant: " RESET "%u\n", bi.biClrImportant);
}