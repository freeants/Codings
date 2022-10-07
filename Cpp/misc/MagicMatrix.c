// C program to generate magic squares
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // for isdigit()
#include <stdbool.h> // for bool type in C

int **matrix;
int N;

bool isOdd;
bool isDoubleEven; // n = 4 * m (m=1,2,3...)
bool isSingleEven; // n = 4 * m + 2

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
 * Print the Matrix to console
 */
void printMatrix(int n)
{

    // Print magic matrix
    printf("The Magic Matrix for n = %d, magic sum %d, ",
           n, n * (n * n + 1) / 2);

    // Print Odd and Even type
    if (isOdd)
        printf("It's odd matrix.\n\n");
    else if (isSingleEven)
        printf("It's single even matrix.\n\n");
    else if (isDoubleEven)
        printf("It's double even matrix.\n\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%2d ", matrix[i][j]);
        printf("\n");
    }
}

/*
 * Build Matrix array
 */
void buildMatrix(int n)
{
    printf("Build 2D matrix ... (size: %d*%d).\n", n, n);
    // Define and allocat memory for dynamic array */
    matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
}

/*
 * Free memory used by Matrix
 */
void freeMem()
{
    for (int i = 0; i < N; ++i)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// A function to generate odd sized magic squares
void generateOddMatrix(int n)
{
    // Initialize position for 1
    int i = n / 2;
    int j = n - 1;

    // One by one put all values in magic square
    for (int num = 1; num <= n * n;)
    {
        if (i == -1 && j == n) // 3rd condition
        {
            j = n - 2;
            i = 0;
        }
        else
        {
            // 1st condition helper if next number
            // goes to out of square's right side
            if (j == n)
                j = 0;

            // 1st condition helper if next number
            // is goes to out of square's upper side
            if (i < 0)
                i = n - 1;
        }
        if (matrix[i][j]) // 2nd condition
        {
            j -= 2;
            i++;
            continue;
        }
        else
            matrix[i][j] = num++; // set number

        j++;
        i--; // 1st condition
    }
    printMatrix(n);
}

void generateDoubleEvenMatrix(int n)
{

    int i, temp;
    int col, row;

    // Initialise
    i = 1;
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            matrix[row][col] = i;
            i++;
        }
    }

    // Revert middle col.
    for (row = 0; row < n / 2; row++)
    {
        for (col = n / 4; col < n / 4 * 3; col++)
        {
            temp = matrix[row][col];
            matrix[row][col] = matrix[n - row - 1][col];
            matrix[n - row - 1][col] = temp;
        }
    }

    // Revert middle row.
    for (col = 0; col < n / 2; col++)
    {
        for (row = n / 4; row < n / 4 * 3; row++)
        {
            temp = matrix[row][col];
            matrix[row][col] = matrix[row][n - col - 1];
            matrix[row][n - col - 1] = temp;
        }
    }

    // Print Matrix
    printMatrix(n);
}

void generateSingleEvenMatrix(int n)
{

    int i, k, temp;
    int col, row;

    // Initialise
    k = n / 2;
    col = (k - 1) / 2;
    row = 0;
    matrix[row][col] = 1;
    // Create single matrix
    for (i = 2; i <= k * k; i++)
    {
        if ((i - 1) % k == 0) //前一个数是3的倍数
        {
            row++;
        }
        else
        {
            // if row = 0, then row = N-1, or row = row - 1
            row--;
            row = (row + k) % k;

            // if col = N, then col = 0, or col = col + 1
            col++;
            col %= k;
        }
        matrix[row][col] = i;
    }

    //根据A生成B、C、D魔方
    for (row = 0; row < k; row++)
    {
        for (col = 0; col < k; col++)
        {
            matrix[row + k][col + k] = matrix[row][col] + k * k;
            matrix[row][col + k] = matrix[row][col] + 2 * k * k;
            matrix[row + k][col] = matrix[row][col] + 3 * k * k;
        }
    }

    // Swap A and C
    for (row = 0; row < k; row++)
    {
        if (row == k / 2) //中间行，交换从中间列向右的m列，N = 2*(2m+1)
        {
            for (col = k / 2; col < k - 1; col++)
            {
                temp = matrix[row][col];
                matrix[row][col] = matrix[row + k][col];
                matrix[row + k][col] = temp;
            }
        }
        else //其他行，交换从左向右m列,N = 2*(2m+1)
        {
            for (col = 0; col < k / 2; col++)
            {
                temp = matrix[row][col];
                matrix[row][col] = matrix[row + k][col];
                matrix[row + k][col] = temp;
            }
        }
    }

    // Swap B and D
    for (row = 0; row < k; row++) //交换中间列向左m-1列，N = 2*(2m+1)
    {
        for (i = 0; i < (k - 1) / 2 - 1; i++)
        {
            temp = matrix[row][k + k / 2 - i];
            matrix[row][k + k / 2 - i] = matrix[row + k][k + k / 2 - i];
            matrix[row + k][k + k / 2 - i] = temp;
        }
    }

    // Print Matrix
    printMatrix(n);
}

void testOddEvenType(int n)
{
    if ((n % 2) != 0)
    {
        isOdd = true;
        generateOddMatrix(n);
        return;
    }
    else if ((n % 4) == 0)
    {
        isDoubleEven = true;
        generateDoubleEvenMatrix(n);
        return;
    }
    else if (((n - 2) % 4) == 0)
    {
        isSingleEven = true;
        generateSingleEvenMatrix(n);
        return;
    }
}

int main(int argc, char const *argv[])
{

    /** Check cmd line args counts */
    if (argc != 2)
    {
        printf("Usage: MagicMatrix N\n");
        return 1;
    }

    /* Input validations, need to be integer */
    if (isInteger(argv[1]))
    {
        N = atoi(argv[1]);
    }
    else
    {
        printf("N need to be a valid integer.\n");
        return 1;
    }

    buildMatrix(N);
    testOddEvenType(N);
    freeMem();

    return 0;
}