/**
 * 1-3.c - Print the table of Fahrenheit to Celsius equivalents.
 * formula C=(5/9)(F-32)
 **/
#include <stdio.h>

int main()
{
    /* Define the variables */
    float C, F, Step, lo, hi;
    Step = 20;
    lo = 0;
    hi = 400;

    for (F = lo; F <= hi; F += Step)
    {
        /* Do convertion and print out */
        C = 5.0 * (F - 32.0) / 9.0;
        printf("%3.0f\t%6.1f\n", F, C);
    }

    return 0;
}
