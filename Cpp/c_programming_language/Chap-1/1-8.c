/**
 * File: 1-8 - Write a program to count blanks, tabs, and newlines.
 */
#include <stdio.h>

int main()
{
    int c, n1, n2, n3;

    n1 = 0; /* count for blanks */
    n2 = 0; /* count for tabs */
    n3 = 0; /* count for newlines */
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++n1;
        }
        else if (c == '\t')
        {
            ++n2;
        }
        else if (c == '\n')
        {
            ++n3;
        }
    }
    printf("blanks %d, tabs %d, newlines %d\n", n1, n2, n3);
    return 0;
}