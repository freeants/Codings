#include<iostream>
using namespace std;

int main()
{
    int num = 10; //Assuming 16 bit integer
    for (int i = 15; i >= 0; i--)
        cout << ((num >> i) & 1);
    cout << endl;
    for (int i = 0; i < 16; i++)
        cout << ((num >> i) & 1);
    cout << endl;
    return 0;
}