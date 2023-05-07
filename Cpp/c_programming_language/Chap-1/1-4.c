/**
 * 1-4.c - Print the table of Celsius to Fahrenheit equivalents.
 * formula C=5*(F-32)/9, F=(9C+160)/5
 **/
#include <stdio.h>

int main()
{
    /* Define the variables */
    float C, F, Step, lo, hi;
    Step = 11.1;
    lo = -17.80;
    hi = 204.5;

    for (C = lo; C <= hi; C += Step)
    {
        /* Do convertion and print out */
        F = (9.0 * C + 160.0) / 5.0;
        printf("%6.1f\t%3.0f\n", C, F);
    }

    return 0;
}
