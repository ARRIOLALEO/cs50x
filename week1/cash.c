#import <stdio.h>
#import <cs50.h>
#import<math.h>
int main(void)
{
    float cash;
    do
    {
        cash = get_float("how many counts you wants to change ?");
    }
    while (cash < 0.0);
    // Rounded in order to not work with decimals
    cash = round(cash * 100);
    int coints = 0;
    int toRemove = 0;
    while (cash >= 25)
    {
        toRemove = cash / 25;
        coints += toRemove;
        cash -= round(toRemove * 25);
    }
    while (cash >= 10)
    {
        toRemove = cash / 10;
        coints += toRemove;
        cash -= round(toRemove * 10);
    }
    while (cash >= 5)
    {
        toRemove = cash / 5;
        coints += toRemove;
        cash -= round(toRemove * 5);
    }
    while (cash >= 1)
    {
        toRemove = cash / 1;
        coints += toRemove;
        cash -= round(toRemove * 1);
    }
    printf("%i", coints);
}
