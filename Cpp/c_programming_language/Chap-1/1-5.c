/**
 * File: 1-5.c - Modify the temperature conversion program 
 * to print the table in reverse order.
 */
#include <stdio.h>
/* print Fahrenheit-Celsius table */
int main()
{
    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    return 0;
}