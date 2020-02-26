#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    //validate arguments to make sure they provide a number.
    if (argc != 2 && !isdigit(argv[1]))
    {
        //break if it isn't right.
        return 1;
    }

    //make k int from arg
    int k = atoi(argv[1]);

    //get string as user input
    string plain = get_string("plaintext:");

    //pring front part cause cs50 makes you add dumb string in front
    printf("ciphertext: ");

    // Loop through every character in string
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        //get char
        char c = plain[i];

        if (isupper(c))
        {
            // shift digit using k + character
            printf("%c", 'A' + (c - 'A' + k) % 26);
        }
        else if (islower(c))
        {
            //same but lowercase
            printf("%c", 'a' + (c - 'a' + k) % 26);
        }
        else
        {
            // if a number or something, don't change
            printf("%c", c);
        }
    }

    printf("\n");
}