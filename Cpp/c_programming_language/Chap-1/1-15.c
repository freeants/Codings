/**
 * 1-15.c - Rewrite the temperature conversion program of 1-3.c
 * to use a function for conversion - Print the table of 
 * Fahrenheit to Celsius equivalents.
 * formula C=(5/9)(F-32)
 **/
#include <stdio.h>

float celsius(float fahr);

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
        printf("%3.0f\t%6.1f\n", F, celsius(F));
    }

    return 0;
}

/* convert fahrenheit to celsius */
float celsius(float fahr)
{
    return 5.0 * (fahr - 32.0) / 9.0;
}