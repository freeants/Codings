/**
 * File: 1-9.c - program to copy its input to its output, replacing
 *  each string of one or more blanks by a single blank.
 */
#include <stdio.h>

#define NONBLANK 'a'

int main()
{
    int c, lastc;

    lastc = NONBLANK;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ')
            putchar(c);
        else if (lastc != ' ')
            putchar(c);
        lastc = c;
    }

    return 0;
}