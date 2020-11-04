//: e2_18.cc

/*
 * Write code to change the value of a pointer. Write code to change the value to which the pointer points.
 */

#include <iostream>

int main()
{
    int a = 100, b = 200;
    int *p1 = &a, *p2 = &b;

    std::cout << a << b << p1 << p2 << *p1 << *p2 << std::endl;

    // change the value of pointer
    p1 = &b;
    // change the value which the pointer points to
    *p2 = b;
    
    std::cout << a << b << p1 << p2 << *p1 << *p2 << std::endl;
    
    return 0;
}