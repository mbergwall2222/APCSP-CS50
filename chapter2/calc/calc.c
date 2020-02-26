#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //fail if they stupid
    if (argc != 4)
    {
        return 1;
    }

    //check if argv[2] is appropriate math thing
    if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != '/' && argv[2][0] != '%')
    {
        return 1;
    }

    //get floats from array
    float firstNum = atof(argv[1]);
    float secondNum = atof(argv[3]);

    //get op from argv
    string operandString = argv[2];
    char operandChar = operandString[0];

    //initialize vars
    float result;
    int bigNum;

    //perform op
    switch (operandChar)
    {
        case '+' :
            result = firstNum + secondNum;
            break;
        case '-' :
            result = firstNum - secondNum;
            break;
        case 'x' :
            result = firstNum * secondNum;
            break;
        case '/' :
            result = firstNum / secondNum;
            break;
        case '%':
            bigNum = (int)(firstNum / secondNum);
            result = firstNum - (secondNum * bigNum);
    }

    //print
    printf("%.6f\n", result);
}