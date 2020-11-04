//: e1_21.cc

/*
 * Write a program that reads two Sales_item objects that
 * have the same ISBN and produces their sum.
 */

 #include <iostream>
 #include "Sales_item.h"

 int main()
 {
     Sales_item item1, item2;
     std::cin >> item1 >> item2;
     //check items if both are identical
     if (item1.isbn() == item2.isbn())
     {
         std::cout << item1 + item2 << std::endl;
         return 0;  // indicate sucess
     }
     else
     {
         std::cerr << "Need same ISBN" << std::endl;
         return -1; // indicate failure
     }
 }