#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    //handle rejections
    if (argc != 3)
    {
        return 1;
    }

    //make days variable
    int days = atoi(argv[1]);
    if (days < 28 || days > 31 || days < 0)
    {
        return 1;
    }

    //make pennies variable
    long long int pennies = atoi(argv[2]);

    if (pennies <= 0)
    {
        return 1;
    }

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