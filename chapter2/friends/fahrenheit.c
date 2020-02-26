#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //handle rejections
    if (argc != 2)
    {
        return 1;
    }

    //Get float as input
    float c = atof(argv[1]);

    //convert c to f
    float f = ((c * 9) / 5) + 32;

    //print result
    printf("F:%.1f\n", f);

}