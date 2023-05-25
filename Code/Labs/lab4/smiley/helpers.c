#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    // 0x5C13E0

    /*
    Loop through image[row]
        Loop through image[col]
            if image[][] == 0
                image[col][row] = 0x5C13E0
    */

    for (int row = 0; row < width; row++)
    {
        for (int col = 0; col < height; col++)
        {
            if (image[col][row].rgbtBlue == 0 && image[col][row].rgbtGreen == 0 && image[col][row].rgbtRed == 0)
            {
                image[col][row].rgbtBlue = 92;
                image[col][row].rgbtGreen = 19;
                image[col][row].rgbtRed = 224;
            }
        }
    }
}
