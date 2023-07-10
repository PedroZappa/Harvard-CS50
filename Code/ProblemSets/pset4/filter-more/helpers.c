#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h> // malloc()

#define RED_COLOR 0
#define GREEN_COLOR 1
#define BLUE_COLOR 2

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each row
    for (int x = 0; x < height; x++)
    {
        // Loop through each pixel
        for (int y = 0; y < width; y++)
        {
            // Get RGB values for current pixel
            float Red = image[x][y].rgbtRed;
            float Green = image[x][y].rgbtGreen;
            float Blue = image[x][y].rgbtBlue;
            // Calculate the average for current pixel's RGB values
            int avg = round((Red + Green + Blue) / 3);
            // Apply grayscale_value to image RGB
            image[x][y].rgbtRed = image[x][y].rgbtGreen = image[x][y].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through rows
    for (int x = 0; x < height; x++)
    {
        // Loop through half of the pixels in each row
        for (int y = 0; y < width / 2; y++)
        {
            // Store current pixel on buffer
            RGBTRIPLE RGB_buffer = image[x][y];
            // Get last pixel and replace current
            // Overwrite current pixel with pixel[i][width - (y + 1)]
            image[x][y] = image[x][width - (y + 1)];
            // Overwrite pixel[i][width - (y + 1)] with buffered value
            image[x][width - (y + 1)] = RGB_buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Allocate memory for array of pixels
    RGBTRIPLE blurred[height][width];

    // Loop through each row
    for (int row = 0; row < height; row++)
    {
        // Loop through each pixel on x-row
        for (int col = 0; col < width; col++)
        {
            // Load original pixels to buffer
            blurred[row][col] = image[row][col];
        }
    }

    // Filter Image
    // Loop through each row
    for (int row = 0; row < height; row++)
    {
        // Loop through each pixel
        for (int col = 0; col < width; col++)
        {
            // Stores self and neighboring pixel color data
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            float pix = 0.00; // Count o'pixels
            // Get neighboring pixels (3x3)
            // Loop through rows
            for (int i = -1; i < 2; i++)
            {
                // Loop through pixels
                for (int j = -1; j < 2; j++)
                {
                    // Init vars
                    int currX = row + i;
                    int currY = col + j;
                    // Check if invalid neighbour
                    if (currX < 0 || currX > (height - 1) || currY < 0 || currY > (width - 1))
                    {
                        continue; // ignore pixel
                    }
                    // get image RGB values
                    totalRed += image[currX][currY].rgbtRed;
                    totalGreen += image[currX][currY].rgbtGreen;
                    totalBlue += image[currX][currY].rgbtBlue;
                    // Keep count of elapsed valid pixels
                    pix++;
                }
                // Calculate average of each R, G and B values of valid neighboring pixels
                blurred[row][col].rgbtRed = round(totalRed / pix);
                blurred[row][col].rgbtGreen = round(totalGreen / pix);
                blurred[row][col].rgbtBlue = round(totalBlue / pix);
            }
        }
    }
    // Write filtered pixels into image
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Write filtered RGB values into each pixel
            image[row][col].rgbtRed = blurred[row][col].rgbtRed;
            image[row][col].rgbtGreen = blurred[row][col].rgbtGreen;
            image[row][col].rgbtBlue = blurred[row][col].rgbtBlue;
        }
    }

    return;
}

// Detect edges
// Sobel operator
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Init image buffer
    RGBTRIPLE buffer[height][width];
    // Init Gx kernel (track horizontal changes)
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    // Init Gy kernel (track vertical changes)
    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    // Edge Detect
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Get row indexes
            int rowIdx[] = {row-1, row, row+1};
            int colIdx[] = {col-1, col, col+1};
            // Init Gx & Gy values of current pixel
            float Gx_red = 0, Gx_green = 0, Gx_blue = 0;
            float Gy_red = 0, Gy_green = 0, Gy_blue = 0;
            // Get neighboring pixels (3x3)
            // Loop through rows
            for (int i = 0; i < 3; i++)
            {
                // Loop through pixels
                for (int j = 0; j < 3; j++)
                {
                    // Init vars
                    int currX = rowIdx[i];
                    int currY = colIdx[j];
                    // Check if valid neighbour
                    if (currX >= 0 && currX < height && currY >= 0 && currY < width)
                    {
                        RGBTRIPLE pixel = image[currX][currY];
                        // Matrix multiplication
                        Gx_red += Gx[i][j] * pixel.rgbtRed;
                        Gx_green += Gx[i][j] * pixel.rgbtGreen;
                        Gx_blue += Gx[i][j] * pixel.rgbtBlue;

                        Gy_red += Gy[i][j] * pixel.rgbtRed;
                        Gy_green += Gy[i][j] * pixel.rgbtGreen;
                        Gy_blue += Gy[i][j] * pixel.rgbtBlue;
                    }
                }
            }
            // Matrix transformation
            // Apply sqrt function to Gx & Gy
            int finalRed = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int finalGreen = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int finalBlue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            // Calculate average of each R, G and B values of valid neighboring pixels
            buffer[row][col].rgbtRed = finalRed > 255 ? 255 : finalRed;
            buffer[row][col].rgbtGreen = finalGreen > 255 ? 255 : finalGreen;
            buffer[row][col].rgbtBlue = finalBlue > 255 ? 255 : finalBlue;
        }
    }
    // Write final image
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Write filtered RGB values into each pixel
            image[row][col] = buffer[row][col];
            image[row][col] = buffer[row][col];
            image[row][col] = buffer[row][col];
        }
    }
    return;
}
