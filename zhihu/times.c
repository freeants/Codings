/*
    File:       times.c - Get Compile time and Current time.
    Copyright:  © 2020-2025 freeants. All rights reserved.
 */

#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t now;
    time(&now);

    printf("Program build time: %s\n", __TIMESTAMP__);
    printf("Current local time: %s", ctime(&now));
    return 0;
}
