//: e1_11.cc

/*
 * Write a program that prompts the user for two integers.
 * Print each number in the range specified by those two integers
 */

#include <iostream>
using namespace std;

int main()
{
    int v1, v2;
    cout << "Enter two integers:" << endl;
    cin >> v1 >> v2;

    int bigger, smaller;
    if (v1 > v2)
    {
        bigger = v1;
        smaller = v2;
    }
    else
    {
        bigger = v2;
        smaller = v1;
    }

    int i = 0;
    i = bigger - smaller;

    if (i == 0 || i == 1)
    {
        cout << "No integer number(s) in between" << endl;
        return 1;
    }

    cout << "Each number in rang [" << smaller << "," << bigger << "]:" << endl;
    while (--i)
        cout << ++smaller << " ";

    cout << endl;
    return 0;
}