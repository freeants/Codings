/*
 * ldo.c - Judge if the input is a Letter, Digit or Others.
 */

#include <stdio.h>

int main()
{
    char c;
    int i = 0;
    
    /* Get inputs for stdin */
    c = getchar();

    /* Test if the character ASCII in CAPS/Lower range */
    if ((c > 64 && c < 91) || (c > 96 && c < 123))
        puts("It's a letter\n");
    else if (c > 49 && c < 58)
        puts("It's a digit\n");
    else
        puts("Other type of characters\n");

    return 0;
}