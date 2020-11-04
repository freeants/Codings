//: e1_23.cc

/*
 * Write a program that reads several transactions and
 * counts how many transactions occur for each ISBN.
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
        int cnt = 1;
        while (std::cin >> Item)    // read remaining items
        {
            if ( Item.isbn() == currItem.isbn() )
            {
                ++ cnt;
            }
            else
            {
                std::cout << currItem << " Occurs " << cnt << " times." << std::endl;
                currItem = Item;    // remember the new items
                cnt = 1;            // reset count
            }
        } // end while
        
        std::cout << currItem << " occurs " << cnt << " times." << std::endl;
    } // end if
    return 0;
}       