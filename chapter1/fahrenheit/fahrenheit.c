#include <cs50.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Get float as input
    float c = get_float("C:");

    //convert c to f
    float f = ((c * 9) / 5) + 32;

    //print result
    printf("F:%.1f\n", f);

}