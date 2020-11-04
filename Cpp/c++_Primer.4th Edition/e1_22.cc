//: e1_22.cc

/*
 * Write a program that reads several transactions for the
 * same ISBN. Write the sum of all the transactions that were read.
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    // currItem is the current inputing item, new inputs to Item
    Sales_item currItem, Item;
    // read first item and ensure we have data to process
    if (std::cin >> currItem)
    {
        while (std::cin >> Item)    // read remaining items
        {
            if ( Item.isbn() == currItem.isbn() )
            {
                std::cout << currItem + Item << std::endl;
            }
            else
            {
                std::cout << currItem << std::endl;
                currItem = Item;    // remember the new items
            }
        } // end while
    } // end if

    return 0;
}       