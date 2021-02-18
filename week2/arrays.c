#import <stdio.h>
#import <cs50.h>
int main(void)
{
    int scores[3];
    int bigSume = 0;
    int size = sizeof(scores) / sizeof(int);
    for(int i = 0 ; i < size ; i++)
    {
        scores[i] = get_int("give me the score %i",i);
        bigSume += scores[i];
    }
    printf("the sume is %f\n",((float)bigSume / 3 ));
}
