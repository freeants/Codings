/*
 * Prob.cc
 */
// a + 10*b + c + 100*d + 10*e + f = sum
// a + c + f = 10 + B
// b + e = 9 + A
// A + B = 8
// A <= 6
// sum = 1008 + 9*A
//
#include <iostream>
#include <iomanip>
using namespace std;

int a, b, c, d, e, f, g, h, A, B, sum;
int arr[10];

bool IsIdentical(int arr[])
{
    for (int i = 0; i < 10; i++)
        for (int j = i + 1; j < 10; j++)
            if (arr[i] == arr[j])
                return false;
    return true;
}

bool IsSumMatch()
{
    if (((a + 10 * b + c + 100 * d + 10 * e + f) == sum))
        return true;
    return false;
}

int main()
{

    //int max = 1056;
    //int min = 42;
    int cnt = 0;

    g = 1;
    d = 9;
    h = 0;

    for (a = 2; a < 9; a++)
        for (b = 2; b < 9; b++)
            for (c = 2; c < 9; c++)
                for (e = 2; e < 9; e++)
                    for (f = 2; f < 9; f++)
                        for (A = 2; A < 7; A++)
                        {
                            sum = 1008 + 9 * A;
                            B = 8 - A;
                            arr[0] = a;
                            arr[1] = b;
                            arr[2] = c;
                            arr[3] = d;
                            arr[4] = e;
                            arr[5] = f;
                            arr[6] = g;
                            arr[7] = h;
                            arr[8] = A;
                            arr[9] = B;
                            if (IsSumMatch() && IsIdentical(arr))
                            {
                                cnt++;
                                cout << "[" << a << ", " << b << c << ", " << d << e << f << "] = " << sum << endl;
                            }
                        }
    cout << cnt << " mixes found." << endl;
    return 0;
}
