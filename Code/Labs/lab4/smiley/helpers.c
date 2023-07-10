#include "helpers.h"

// Change all black pixels to a color of your choosing
void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through image's rows
    for (int row = 0; row < width; row++)
    {
        // Loop through current row's columns
        for (int col = 0; col < height; col++)
        {
            // if image's RGB == black
            if (image[col][row].rgbtBlue == 0 && image[col][row].rgbtGreen == 0 && image[col][row].rgbtRed == 0)
            {
                // Set RGB to 0x5C13E0
                image[col][row].rgbtBlue = 92;
                image[col][row].rgbtGreen = 19;
                image[col][row].rgbtRed = 224;
            }
        }
    }
}
