#include "helpers.h"

#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through pixel rows
    for (int i = 0; i < height; i++)
    {
        // Loop through pixel cols
        for (int j = 0; j < width; j++)
        {
            // Convert pixels to floats
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            // Calculate Average value
            int average = round((Red + Green + Blue) / 3);
            // Assign average to each RGB element
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through pixel rows
    for (int i = 0; i < height; i++)
    {
        // Loop through pixel cols
        for (int j = 0; j < width; j++)
        {
            // Convert to float
            float ogRed = image[i][j].rgbtRed;
            float ogGreen = image[i][j].rgbtGreen;
            float ogBlue = image[i][j].rgbtBlue;

            // Calculate Sepia
            int sepiaRed = round(.393 * ogRed + .769 * ogGreen + .189 * ogBlue);
            int sepiaGreen = round(.349 * ogRed + .686 * ogGreen + .168 * ogBlue);
            int sepiaBlue = round(.272 * ogRed + .534 * ogGreen + .131 * ogBlue);

            // If pixel sepia{Color} > 255 == 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Update image pixel values with Sepia Filter
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through pixel rows
    for (int i = 0; i < height; i++)
    {
        // Loop through pixel half its cols
        for (int j = 0; j < width / 2; j++)
        {
            // Create RGB temp array and store current value j
            RGBTRIPLE RGB_temp = image[i][j];
            // Swap image[i][width - (j + 1)] to current element
            image[i][j] = image[i][width - (j + 1)];
            // Move value from temp to image[i][width - (j + 1)]
            image[i][width - (j + 1)] = RGB_temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer[height][width];
    // Copy image into a buffer
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer[i][j] = image[i][j];
        }
    }

    // Loop through image[][] pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Stores self and neighboring pixel color data
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;

            // Get neighboring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    // check if neighboring pixel is valid
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue; // ignore pixel
                    }

                    // Get image value
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    // Keep count of valid pixels
                    counter++;
                }

                // Calculate average of neighboring pixels
                buffer[i][j]. rgbtRed = round(totalRed / counter);
                buffer[i][j]. rgbtGreen = round(totalGreen / counter);
                buffer[i][j]. rgbtBlue = round(totalBlue / counter);
            }
        }
    }

    // Copy filtered pixels into image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = buffer[i][j].rgbtRed;
            image[i][j].rgbtGreen = buffer[i][j].rgbtGreen;
            image[i][j].rgbtBlue = buffer[i][j].rgbtBlue;
        }
    }

    return;
}
