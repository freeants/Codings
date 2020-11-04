//: e1_10.cc

/*
 * Use the decrement (--)
 * operator to write a while that prints the numbers from ten down to zero.
 */

 #include <iostream>
 using namespace std;

 int main()
 {
     int i = 10;
     while (i)
     {
        cout << i <<" ";
        i--;
     }
    cout <<endl;    
    return 0;
 }