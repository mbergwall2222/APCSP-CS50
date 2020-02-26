#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

int main(int argc, char *argv[])
{

    //make sure they give a hash
    if (argc != 2)
    {
        return 1;
    }

    //make vars
    char salt[2],
         password[5],
         dict[53];

    //make dictionary of characters to brute force them
    dict[0] = '\0';

    //dictionary loop
    for (int i = 'A', count = 1; i <= 'z'; i++, count++)
    {
        if (i > 'Z' && i < 'a')
        {
            continue;
        }
        dict[count] = i;
    }

    //copy first 2 of hash to salt
    strncpy(salt, argv[1], 2);


    // massive loop to try every character in password
    for (int i = 1; i < 52; i++)
    {
        password[0] = dict[i];
        for (int j = 0; j < 52; j++)
        {
            password[1] = dict[j];
            for (int k = 0; k < 52; k++)
            {
                password[2] = dict[k];
                for (int l = 0; l < 52; l++)
                {
                    password[3] = dict[l];
                    for (int p = 0; p < 52; p++)
                    {
                        password[4] = dict[p];
                        if (strcmp(argv[1], crypt(password, salt)) == 0)
                        {
                            //it worked? yay print out password
                            printf("%s\n", password);
                        }
                    }
                }
            }
        }
    }
}