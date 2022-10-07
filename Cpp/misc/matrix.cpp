#include <iostream>
#include <iomanip>
using namespace std;

void createSquare(int **array, int r, int c)
{
    int i, j, count = 1, range;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            array[i][j] = 0; // initialize all elements with 0

    range = r * c;
    i = 0;
    j = c / 2;
    array[i][j] = count;

    while (count < range)
    {
        count++;
        if ((i - 1) < 0 && (j - 1) < 0) // when both row and column crosses the range
            i++;
        else if ((i - 1) < 0)
        { // when only row crosses range, set i to last row, and decrease j
            i = r - 1;
            j--;
        }
        else if ((j - 1) < 0)
        { // when only col crosses range, set j to last column, and decrease i
            j = c - 1;
            i--;
        }
        else if (array[i - 1][j - 1] != 0) // when diagonal element is not empty, go to next row
            i++;
        else
        {
            i--;
            j--;
        }
        array[i][j] = count;
    }

    // Printing the square
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            cout << setw(3) << array[i][j];
        cout << endl;
    }
}

int main()
{
    int **matrix;
    int row, col;
    cout << "Enter the order(odd) of square matrix :";
    cin >> row;
    col = row;

    matrix = new int *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
    }
    createSquare(matrix, row, col);

    return 0;
}