/*
    largest4digits.c - find the largest 4 digits number that meet these two conditions:
        1. all digits sums up to 14,
        2. contains one 0 when read.
    Author: freeants, All rights reserved.
*/

#include <stdio.h>
typedef struct
{
    int kilDigit;
    int hunDigit;
    int tenDigit;
    int oneDigit;
} fourDigitInt;

int main(int argc, char const *argv[])
{
    fourDigitInt num;

    /* loop over all 4 digits numbers */
    for (size_t i = 9000; i < 9999; i++)
    {
        /* Do the extraction of digits */
        num.kilDigit = i / 1000;
        num.hunDigit = i / 100 - num.kilDigit * 10;
        num.tenDigit = i / 10 - num.kilDigit * 100 - num.hunDigit * 10;
        num.oneDigit = i - num.kilDigit * 1000 - num.hunDigit * 100 - num.tenDigit * 10;

        if ((num.kilDigit + num.hunDigit + num.tenDigit + num.oneDigit) == 14)
        {
            printf("%zu ", i);
        }
    }
    printf("\n");
    return 0;
}
