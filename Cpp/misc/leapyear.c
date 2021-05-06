/*
    leapyear.c - check if a year is a leap/common year from command line.
    Author: freeants, All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>  // for atoi()
#include <ctype.h>   // for isdigit()
#include <stdbool.h> // for bool type in C

int year; // year in YYYY integer format to be checked

/*
 * Test if it's an integer input
 */
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

/*
 * Test if it's leap year
 */
bool isLeap(int y)
{
    if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    /** Check cmd line args */
    if (argc != 2)
    {
        printf("Usage: leapyear YYYY\n");
        return 1;
    }

    /** Input validations */
    if (isInteger(argv[1]))
    {
        year = atoi(argv[1]);
    }
    else
    {
        printf("YYYY need to be integer.\n");
        return 1;
    }

    if (isLeap(year))
        printf("%d is a leap year\n", year);
    else
        printf("%d is a common year\n", year);
    return 0;
}