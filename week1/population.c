#import <cs50.h>
#import <stdio.h>
int main(void)
{
 int n ;
// here i collect the data till the user inset a number biggre than 9
 do
 {
      n = get_int("Start size :");
 }
 while(n < 9);
 int end;
 do
 {
      end = get_int("End size");
 }
 while( end < n);
 int years = 0;
if( end != n ){
    do
 {
     int born =  n / 3;
     int die = n / 4;
    //  add the diference between bors and die
     n = n + (born - die);
    years++;
 }
 while(n <  end);
}
//  i stats the counter of years



 printf("Years: %i\n",years);
}
