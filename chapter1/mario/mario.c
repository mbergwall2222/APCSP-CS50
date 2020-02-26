#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //initialize variables
    int height;

    //get + validate height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //counter
    int counter = 0;

    //start at first row (top)
    for (int row = 0; row < height; row++)
    {
        //if at height, stop
        if (counter != height)
        {
            //print spaces
            for (int spaces = (height - 1) - counter; spaces > 0; spaces--)
            {
                printf(" ");
            }

            //print hashes
            for (int hashes = 0; hashes <= counter; hashes++)
            {
                printf("#");
            }

            //mirror image

            printf("  ");

            for (int hashes = 0; hashes <= counter; hashes++)
            {
                printf("#");
            }

            //print new line
            printf("\n");

            //increase counter for next row
            counter++;
        }
    }
}