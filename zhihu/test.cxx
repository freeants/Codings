#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 5;

int searchNearest(int anArray[], int key)
{
    int value = abs(key - anArray[0]);
    int num = anArray[0];

    for (int x = 0; x < MAX; x++)
    {
        if (value > abs(key - anArray[x]))
        {
            value = abs(key - anArray[x]);
            num = anArray[x];
        }
    }

    return num;
}

int main()
{
    int A[MAX] = {3, 7, 12, 8, 10};

    int search;

    int nearest;

    cout << "Enter a number to search: ";

    cin >> search;

    nearest = searchNearest(A, search);

    cout << "The nearest number is: " << nearest << endl;

    //system("pause");
    return 0;
}