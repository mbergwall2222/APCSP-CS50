#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //variables
    int cents;

    //loop until cents is valid
    do
    {
        float dollars = get_float("Change owed: ");
        cents = round(dollars * 100);
    }
    while (cents <= 0);

    //output
    printf("%d\n", (cents / 25) + ((cents % 25) / 10) + (((cents % 25) % 10) / 5) + (((cents % 25) % 10) % 5));
}