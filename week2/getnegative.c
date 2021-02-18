#import <cs50.h>
#import <stdio.h>
int get_negative_in();
int main(void)
{
    int negative = get_negative_in();
    printf("this is the negative that you sended %i\n",negative);
}

int get_negative_in()
{
    int miNumber;
    do{
        miNumber = get_int("get me a negative number");
    }while(miNumber > 0);
    return miNumber;
}
