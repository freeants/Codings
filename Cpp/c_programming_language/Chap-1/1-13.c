/**
 * File: 1-13.c - Write a program to print a histogram of the lengths
 * of words in its input.
 */
#include <stdio.h>

#define MAXHIST 15 /* max length of histogram  */
#define MAXWORD 11 /* max length of a word     */
#define IN 1       /* inside a word            */
#define OUT 0      /* outside a word           */

/* print horizontal histogram                  */
int main(int argc, char const *argv[])
{
    int c, i, nc, state;
    int len;
    int maxvalue;
    int ovflow;
    int wl[MAXWORD];

    state = OUT;
    nc = ovflow = 0;
    for (i = 0; i < MAXWORD; ++i)
        wl[i] = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            if (nc > 0)
                if (nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;
            nc = 0;
        }
        else if (state == OUT)
        {
            state = IN;
            nc = 1;
        }
        else
            ++nc;
    }
    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i)
        if (wl[i] > maxvalue)
            maxvalue = wl[i];

    for (i = 1; i < MAXWORD; ++i)
    {
        printf("%5d - %5d : ", i, wl[i]);
        if (wl[i] > 0)
        {
            if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
                len = 1;
        }
        else
            len = 0;
        while (len > 0)
        {
            putchar('*');
            --len;
        }
        putchar('\n');
    }
    if (ovflow > 0)
        printf("There are %d word >= %d\n", ovflow, MAXWORD);

    return 0;
}
