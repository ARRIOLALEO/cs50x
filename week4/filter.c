#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE  buffer;
    for (int i = 0 ; i <  height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            buffer =  image[i][j];
            int media = round((buffer.rgbtBlue + buffer.rgbtGreen + buffer.rgbtRed) / 3.0);
            buffer.rgbtBlue  = media;
            buffer.rgbtGreen = media;
            buffer.rgbtRed = media;
            image[i][j] = buffer;
        }
    }
    return;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0 ; i <  height ; i++)
    {
        for (int j = 0 ; j < width; j++)
        {
            RGBTRIPLE  buffer;
            int red =  round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int green = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int blue  = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            if (red > 255)
            {
                buffer.rgbtRed = 255;
            }
            else
            {
                buffer.rgbtRed = red;
            }
            if (green > 255)
            {
                buffer.rgbtGreen = 255;
            }
            else
            {
                buffer.rgbtGreen = green;
            }
            if (blue > 255)
            {
                buffer.rgbtBlue = 255;
            }
            else
            {
                buffer.rgbtBlue = blue;
            }
            image[i][j] = buffer;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;
    int medium = floor(width / 2.0);
    for (int i = 0 ; i < height; i++)
    {
        int counter = width - 1;
        for (int j = 0 ; j < medium ; j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][counter];
            image[i][counter] = buffer;
            counter--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE buffer[height][width] ;
//  here i create a clone of the image that i will modify
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            buffer[i][j] = image[i][j];
        }
    }
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {

            float counter = 0.00;
            int red   = 0;
            int blue  = 0;
            int green = 0;
            //   the corners
            // center
            if ((i >= 0 && j  >= 0))
            {
                red += buffer[i][j].rgbtRed;
                blue += buffer[i][j].rgbtBlue;
                green += buffer[i][j].rgbtGreen;
                counter++;
            }
            // center left
            if (i >= 0 && j - 1 >= 0)
            {
                red += buffer[i][j - 1].rgbtRed;
                blue += buffer[i][j - 1].rgbtBlue;
                green += buffer[i][j - 1].rgbtGreen;
                counter++;
            }
            // up center
            if ((i - 1 >= 0 && j  >= 0))
            {
                red += buffer[i - 1][j].rgbtRed;
                blue += buffer[i - 1][j].rgbtBlue;
                green += buffer[i - 1][j].rgbtGreen;
                counter++;
            }
            //  up center
            if ((i - 1 >= 0 && j - 1  >= 0))
            {
                red += buffer[i - 1][j - 1].rgbtRed;
                blue += buffer[i - 1][j - 1].rgbtBlue;
                green += buffer[i - 1][j - 1].rgbtGreen;
                counter++;
            }
            //  up right
            if ((i - 1 >= 0 && j + 1  >= 0) && (j + 1 < (width)))
            {
                red += buffer[i - 1][j + 1].rgbtRed;
                blue += buffer[i - 1][j + 1].rgbtBlue;
                green += buffer[i - 1][j + 1].rgbtGreen;
                counter++;
            }
            // right center
            if ((i  >= 0 && j + 1  >= 0) && (j + 1 < (width)))
            {
                red += buffer[i][j + 1].rgbtRed;
                blue += buffer[i][j + 1].rgbtBlue;
                green += buffer[i][j + 1].rgbtGreen;
                counter++;
            }

            //    down part
            if ((i + 1 < height) && j - 1 >= 0)
            {
                red += buffer[i + 1][j - 1].rgbtRed;
                blue += buffer[i + 1][j - 1].rgbtBlue;
                green += buffer[i + 1][j - 1].rgbtGreen;
                counter++;
            }
            if ((i + 1 < height) && j >= 0)
            {
                red += buffer[i + 1][j].rgbtRed;
                blue += buffer[i + 1][j].rgbtBlue;
                green += buffer[i + 1][j].rgbtGreen;
                counter++;
            }
            if ((i + 1 < height  && j >= 0) && (j + 1 < width))
            {
                red += buffer[i + 1][j + 1].rgbtRed;
                blue += buffer[i + 1][j + 1].rgbtBlue;
                green += buffer[i + 1][j + 1].rgbtGreen;
                counter++;
            }


            image[i][j].rgbtRed = round(red / counter);
            image[i][j].rgbtBlue = round(blue / counter);
            image[i][j].rgbtGreen = round(green / counter) ;
            counter = 0;
        }
    }
    return;
}
