/*
    File: c_rand.c - Generate n random numbers in [x, y]
    Copyright (c), freeants, 2021. All rights reserved. 
*/

#include <stdio.h>
#include <stdlib.h>  // for srand()
#include <time.h>    // for time()
#include <ctype.h>   // for isdigit()
#include <stdbool.h> // for bool type in C

int N, X, Y; // Number of randoms; range for random numbers [x, y]
int *a;      // Array to store the sorted numbers

/*
 * The Insertion Sort method.
 */
void insertionSort(int *arr, int length)
{
    int i, j, tmp;
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

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
 * Generate random number in rang [x, y]
 */
int GenRndNum(int x, int y)
{
    /* rand() % (max_number + 1 - minimum_number) + minimum_number */
    return (rand() % (y + 1 - x) + (x));
}

/*
 * Build n randoms in [x, y]
 */
void BuildRandoms(int n, int x, int y)
{
    printf("Generating %d random numbers between [%d, %d] in ascending order ...\n", n, x, y);

    /* Define and allocate memory for dynamic array */
    a = (int *)malloc(n * sizeof(int));

    /* Use current time as random seed */
    srand(time(0));
    for (size_t i = 0; i < n; i++)
    {
        /* Assign n randoms to array */
        a[i] = GenRndNum(x, y);
    }
}

/*
 * Print the sorted array of randoms
 */
void printArray(int *arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    /** Check cmd line args */
    if (argc != 4)
    {
        printf("Usage: c_rand n x y\t//n: number of randoms, x and y is the rang.\n");
        return 1;
    }

    /* Input validations */
    if (isInteger(argv[1]) && isInteger(argv[2]) && isInteger(argv[3]))
    {
        N = atoi(argv[1]);
        X = atoi(argv[2]);
        Y = atoi(argv[3]);
    }
    else
    {
        printf("x, y & n need to be integers.\n");
        return 1;
    }

    /* Build N numbers of randoms in [X, Y] */
    BuildRandoms(N, X, Y);

    /* Sort the randoms in ascending order */
    insertionSort(a, N);

    /* Print the sorted array */
    printArray(a, N);

    /* Free array */
    free(a);

    return 0;
}
