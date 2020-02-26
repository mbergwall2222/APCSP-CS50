#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //make days variable
    int days = -1;
    do
    {
        //get days until it's valid
        days = get_int("Days in month: ");
    }
    while (days < 28 || days > 31 || days < 0);

    //make pennies variable
    long long int pennies = -1;

    do
    {
        //get pennies until valid
        pennies = get_int("Pennies on First Day: ");
    }
    while (pennies <= 0);

    //make total variable
    long long int total = 0;

    //do da math
    for (int i = 0; i < days; i++)
    {
        total += pennies;
        pennies *= 2;
    }

    //output final data
    printf("$%.2f\n", (double)(total / 100.0));

}