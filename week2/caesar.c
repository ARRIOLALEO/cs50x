#import <stdio.h>
#import <cs50.h>
#import <string.h>
#import <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    if (!argv[1])
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    else if (atoi(argv[1]) <= 0)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        char myArray[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int newKey ;
        string plainText = get_string("gime the String to emcript ");
        int ciperLeter = 0;
        string solution = "";
        bool isUpper ;
        printf("ciphertext: ");
        for (int  i = 0, n = strlen(plainText); i < n ; i++)
        {
            bool isTrue = true;
            isUpper = false;
            char otherLeter = plainText[i];
            if (((int)otherLeter >= 97 && (int)otherLeter <= 122) || ((int)otherLeter >= 65 && (int)otherLeter <= 90))
            {
                for (int j = 0 ; isTrue == true ; j++)
                {
                    char myLt = myArray[j] ;
                    if ((int)otherLeter >= 65 && (int)otherLeter <= 90)
                    {
                        isUpper = true;
                    }
                    otherLeter = tolower(otherLeter);
                    if (myLt == otherLeter)
                    {
                        ciperLeter = j;
                        isTrue = false;
                    }
                }
                //   till here i got the number in the Array
                //  and now i add the key of the ciper
                if ((ciperLeter + key) > 25)
                {
                    for (int k = 0 ; k < key ; k++)
                    {
                        if (ciperLeter  == 25)
                        {
                            ciperLeter = 0 ;
                        }
                        else
                        {
                            ciperLeter++;
                        }
                    }
                }
                else
                {
                    ciperLeter += key;
                }
                if (!isUpper)
                {
                    printf("%c", myArray[ciperLeter]);
                }
                else
                {
                    printf("%c", toupper(myArray[ciperLeter]));
                }
            }
            else
            {
                printf("%c", otherLeter);
            }
        }
        printf("\n");
    }
}
