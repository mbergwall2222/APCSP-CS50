#include <cs50.h>
#include <stdio.h>

int main(void)
{
//variables
    long long int isbn, temp;

    //get user input
    isbn = get_long_long("ISBN: ");
    int k = 0;

    //loop
    for (int i = 10; i > 0; i--)
    {
        //add to k variable
        k += (isbn % 10) * i;

        //get next digit in isbn
        isbn = isbn / 10;
    }

    //print output
    printf((k % 11 == 0 ? "YES%s" : "NO%s"), "\n");
}