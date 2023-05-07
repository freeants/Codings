/*
    sec2min.c - Converts inputed senconds to minutes and seconds.
    Author: freeants, All rights reserved.
*/

#include <stdio.h>
typedef struct
{
    int min;
    int sec;
} time;

int main(int argc, char const *argv[])
{
    time mytime;
    int seconds;

    /* ask for input */
    printf("Enter seconds: ");
    scanf("%d", &seconds);

    /* use integer division and mod for min & sec */
    mytime.min = seconds / 60;
    mytime.sec = seconds % 60;

    /* out put results */
    printf("%d seconds is %d minutes and %d seconds.\n", seconds, mytime.min, mytime.sec);
    return 0;
}
