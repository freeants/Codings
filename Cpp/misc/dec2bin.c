/*
    File:       dec2bin.c - Convert decimals to binary form.
    Copyright:  © 2020-2025 freeants. All rights reserved.
 */

#include <stdio.h>
#include <stdbool.h> // for bool type in C
#include <ctype.h>   // isdigit()
#include <stdlib.h>  // atoi()
#include <string.h>  // strcat()

bool isInteger(const char *s)
{
    bool isValidInteger = true;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
            isValidInteger = false;
    }
    return isValidInteger;
}

char *toBinString(int n)
{
    /* assuming 16 bit int */
    char src[16];
    char *str = malloc(16);
    for (int i = 15; i >= 0; i--)
    {
        sprintf(src, "%d", ((n >> i) & 1));
        strcat(str, src);
    }
    return str;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        /* prompt for usage */
        printf("Usage: dec2bin n    // n is an integer number\n");
        return 1;
    }
    const char *str = argv[1];
    /* code for printing to stdout */
    if (isInteger(str))
    {
        int num;
        num = atoi(str);
        printf("HEX: %x\n", num);
        printf("OCT: %o\n", num);
        printf("DEC: %d\n", num);
        printf("BIN: %s\n", toBinString(num));
    }
    else
    {
        /* prompt for error msg */
        printf("Input integers only.\n");
    }
    return 0;
}