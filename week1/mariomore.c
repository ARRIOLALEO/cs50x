#import <stdio.h>
#import <cs50.h>
int main(void)
{
    int n;
    // get values till the value es greater than 0 but less than 9
    do
    {
        n = get_int("Height");
    }
    while ((n < 1) || (n >= 9));

    for (int i = 0 ; i < n ; i++)
    {
        // inversal printing
        for (int j = n - 1; j >= 0 ; j--)
        {
            // we print the blocks
            if (j <= i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("  ");
        // here i print the inverted blocks
        for (int w = 0 ; w < n ; w++)
        {
            if (w <= i)
            {
                printf("#");
            }
        }
        //  added the return line
        printf("\n");
    }
}
