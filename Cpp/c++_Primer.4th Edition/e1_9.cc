//: e1_9.cc

#include <iostream>
using namespace std;

int main()
{
    int i = 50, sum = 0;

    while (i <= 100)
    {
        sum += i;
        i++;
    }

    cout <<"The sum from 50 to 100 inclusive is " << sum <<endl;

    return 0;
}