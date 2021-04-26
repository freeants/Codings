/*
    handle2DArray.c - Find sum, average of a M * N 2D array and sort each column.
    Author: freeants, All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>  // for srand()
#include <time.h>    // for time()
#include <ctype.h>   // for isdigit()
#include <stdbool.h> // for bool type in C

int M, N;           // Array dimension M * N
int **a;            // The 2D array
float sum, average; // the sum and average of the array
int *col;           // The working array that saves all the column items

/*
 * Print out 2D array the Java style as "Arrays.deepToString".
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
                printf("%d, ", arr[r][c]); // print row items with ','
            else
                printf("%d", arr[r][c]); // print lat row items without ','
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
 * Print out 1D array the Java style as "Array.toString".
 */
void toString(int *arr)
{
    printf("[");
    for (size_t i = 0; i < M; i++)
    {
        if (i != M - 1)
            printf("%d, ", arr[i]); // print items with ','
        else
            printf("%d", arr[i]); // print items without ','
    }
    printf("]\n");
}

/*
 * Free memory allocated for 2D array.
 */
void FreeMem()
{
    for (int i = 0; i < M; ++i)
    {
        free(a[i]);
    }
    free(a);
    free(col);
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
    // allocate memory for the required 2D array.
    col = (int *)malloc(m * sizeof(int));

    // assign values to array with random number
    srand(time(0)); // use current time as random seed
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = GenRndNum();
    // print the 2D array
    deepToString(a);
}

/*
 * Sum up all items in the array.
 */
float Sumof2DArray(int m, int n)
{
    sum = 0;
    // loop through all items and sum them up
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            sum += a[i][j];
    return sum;
}
/*
 * Get the average of the array.
 */
float Averageof2DArray(int m, int n)
{
    return (sum / (float)(m * n));
}

/*
 * Print the sum and average of the array
 */
void PrintSumAverage()
{
    printf("     Sum of the array: %.2f\n", Sumof2DArray(M, N));
    printf(" Average of the array: %.2f\n", Averageof2DArray(M, N));
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
 * Sort array Cols and print sorted itmes.
 */
void SortArrayCols(int **arr)
{

    for (int c = 0; c < N; c++)
    { // for each col from 0 to N
        for (int r = 0; r < M; r++)
        {
            col[r] = arr[r][c]; // assign col items to row[] array
        }
        insertionSort(col, M); // sort each col arrays, total N times
        printf("Sorted items @ col[%d]: ", c);
        toString(col);
    }
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
    PrintSumAverage();
    // Sum up all row maxes and print
    SortArrayCols(a);
    // Free allocated memery
    FreeMem();

    return 0;
}