//: e1_16.cc

#include <iostream>
using namespace std;

int main()
{
    int val;
    int sum = 0;

    cout <<"Enter numbers below:" <<endl;
    while (cin >> val)
        sum += val;

    cout <<"Sum of inputs: " <<sum <<endl;
    return 0;
}