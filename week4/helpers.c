#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE  buffer;
    for(int i = 0 ; i <  height ; i++){
        for( int j = 0 ; j < width ; j++){
           buffer=  image[i][j];
           int media = ceil((buffer.rgbtBlue + buffer.rgbtGreen + buffer.rgbtRed) / 3.0);
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
        RGBTRIPLE  buffer;
        for(int i = 0 ; i <  height ; i++){
        for( int j = 0 ; j < width ; j++){
           buffer.rgbtBlue  = ceil(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
           buffer.rgbtGreen = ceil(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
           buffer.rgbtRed =   ceil(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
           image[i][j] = buffer;
        }
        }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
