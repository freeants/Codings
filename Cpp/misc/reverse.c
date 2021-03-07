/*
    reverse.c - Reverse the order of inputed two-digits integer.
    Author: freeants, All rights reserved.
*/

#include <stdio.h>
typedef struct
{
    int tenDigit;
    int oneDigit;
} twoDigitInt;

int main(int argc, char const *argv[])
{
    int number;
    twoDigitInt myNum;

    /* Ask for input */
    printf("Enter a two-digit integer: ");
    scanf("%d", &number);

    /* Do the extraction of digits */
    myNum.tenDigit = number / 10;
    myNum.oneDigit = number - myNum.tenDigit * 10;

    /* Output */
    printf("  Reversed order of input: %d%d\n", myNum.oneDigit, myNum.tenDigit);

    return 0;
}
