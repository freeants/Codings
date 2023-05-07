/*
    Sort2DArray.c - Find max item of each row, output each and their sum.
    Author: freeants, All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>  // for srand()
#include <time.h>    // for time()
#include <ctype.h>   // for isdigit()
#include <stdbool.h> // for bool type in C

int M, N;       // Array dimension M * N
int **a;        // The 2D array
int *max, *row; // The working array that saves all the max row items

/*
 * Arrays.deepToString. No need in java
 */
void deepToString(int **arr)
{
    printf("[");
    for (int r = 0; r < M; r++)
    {
        // for each row from 0 to M
        printf("[");
        for (int c = 0; c < N; c++)
        {
            if (c != N - 1)
                printf("%d,", arr[r][c]); // print row items with ','
            else
                printf("%d", arr[r][c]); // print last row items without ','
        }
        // handling last row ',' format
        if (r != M - 1)
            printf("], ");
        else
            printf("]");
    }
    printf("]\n");
}

/*
 * Free memory. No need in java
 */
void FreeMem()
{
    for (int i = 0; i < M; ++i)
    {
        free(a[i]);
    }
    free(a);
    free(max);
    free(row);
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
 * Generate random number in rang [-100,100]
 */
int GenRndNum()
{
    return (rand() % (201) + (-100));
}

/*
 * Build 2D array with random numbers, to save input time
 */
void Build2DArray(int m, int n)
{
    printf("Build 2D array ... (size: %d*%d)\n", M, N);
    // Define and allocat memory for dynamic array */
    a = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; ++i)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }
    max = (int *)malloc(m * sizeof(int));
    row = (int *)malloc(n * sizeof(int));

    // assign values to array with random number
    srand(time(0)); // use current time as random seed
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = GenRndNum();
    // print the 2D array
    deepToString(a);
}

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
 * Print Max row item of the array
 */
void PrintMaxRowItem(int **arr)
{

    for (int r = 0; r < M; r++)
    { // for each row from 0 to M
        for (int c = 0; c < N; c++)
        {
            row[c] = a[r][c]; // assign row items to row[] array
        }
        insertionSort(row, N); // sort each row array, total M times
        printf("Max @ row[%d]: %d\n", r, row[N - 1]);
        max[r] = row[N - 1]; // save each row max to max[]
    }
}

/*
 * Sum up max row items
 */
void SumMax()
{
    int s = 0;
    for (int i = 0; i < M; i++)
        s += max[i];
    printf("Sum of all max row item: %d\n", s);
}

int main(int argc, char const *argv[])
{
    /** Check cmd line args */
    if (argc != 3)
    {
        printf("Usage: Sort2DArray m n\n");
        return 1;
    }

    // Input validations
    if (isInteger(argv[1]) && isInteger(argv[2]))
    {
        M = atoi(argv[1]);
        N = atoi(argv[2]);
    }
    else
    {
        printf("M & N need to be integers.\n");
        return 1;
    }

    // Build the array with random numbers
    Build2DArray(M, N);
    // Print the biggest of each row
    PrintMaxRowItem(a);
    // Sum up all row maxes and print
    SumMax();
    // Free allocated memery
    FreeMem();

    return 0;
}
