#import <stdio.h>
#import <cs50.h>
#import <string.h>
#import <ctype.h>
#import <math.h>
int main(void)
{
    string text = get_string("What thext you need me to Check :");
    int numberOfCharacters = strlen(text);
    int words = 1;
    int sentences = 0;
    int leters = 0;
    for (int i = 0 ; i < numberOfCharacters; i++)
    {
        int leter = tolower(text[i]);
        //  if this is space we considered this a word
        if
        (leter == 32)
        {
            words++;
        }
        // we handal the centences if they have  "." "!" or "?"
        else if
        (leter == 33 ||  leter == 46 || leter == 63)
        {
            sentences++;
        }
        // if not they are just characters
        else if
        (leter >= 97  && leter <= 122)
        {
            leters++;
        }
    }
    //  i make the calculation of the level of complexity of the text
    float resolution = (((leters / (float)words) * 100.00) * 0.0588) - (((sentences  / (float)words) * 100.00) * 0.296) - 15.8;
    if (resolution < 1)
    {
        printf("Before Grade 1\n");
    }
    else if
    (resolution > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(resolution));
    }
}
