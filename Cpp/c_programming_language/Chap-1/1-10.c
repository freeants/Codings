/**
 * File: 1-10.c - Replace tabs, backspaces and backslashes
 * with visible characters.
 */
#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF)
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);

    return 0;
}