/*******************************************************************************
 ** Author: Patrick Mullaney
 ** Description:  Main file for Shopping List.  Shopping list creates a grocery
 ** list by  prompting user to enter items and stores pointers to those items 
 ** in an array.
 ** Date: 10/23/16
 *******************************************************************************/

#include <iostream>
#include "Item.hpp"
#include "List.hpp"
#include <string>
#include "Menu.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int start = startMenu();

    // Create list
    if(start == 1)
    {
        // Create list.
        List grocList;
        
        // Get list size and itemNumber.
        int listSize = grocList.getSize();
        int itemNumber = grocList.getNumber();
        
        // User selection for whether to add/remove item or check out.
        int selection = menu();
        
        while(selection != 3)
        {
            // If user selects add item.
            if(selection == 1)
            {
                    itemNumber = grocList.getNumber();
                    //cout << "item number: " << itemNumber << endl;  ***for testing
        
                    // Create item (prompts user for Item info).
                    Item* newItem = grocList.createItem();
        
                    // Get array.
                    Item** itemArray = grocList.getArray();
        
                    // First item is automatically added to the list.
                    if(itemNumber == 0)
                    {
                        grocList.addItem(newItem, itemNumber);
                    }
                    // Match tracks whether there is a duplicate item in array.
                    int match = 0;
     
                    // Loop through items in list to determine whether there is a matching duplicate.
                    for(int i = 0; i < itemNumber; i++)
                    {
                        // If there is an item pointer in the array.
                        if(itemArray[i])
                        {   //Overload equality operator to determiine if it is a duplicate.
                            if(*itemArray[i]==*newItem)
                            {   // Increment match if there is a duplicate.
                                match+=1;
                                cout << "Item is already on list. " << endl;
                            }
                        }
                    }
                    // If there is no match in the list, add Item to list.
                    if((match == 0) && (itemNumber > 0))
                    {
                        grocList.addItem(newItem, itemNumber);
                    }
       
                    // Get updated list size and item number after item.
                    listSize = grocList.getSize();
                    itemNumber = grocList.getNumber();
    
                    // If item number equals listSize, resize the array.
                    if(itemNumber == listSize)
                    {
                        grocList.addList(&grocList, listSize);
                    }
                    // Back to menu.
                    selection = menu();
            }
            // If user selects to remove item.
            if(selection == 2)
            {
                // If at least one item in cart.
                if(itemNumber > 0)
                {
                        string name;
                        cout << "Please enter name of item to be removed." << endl;
                        cin >> name;
                        grocList.removeItem(name);
                }
                // Error message if cart is empty
                else if(itemNumber == 0)
                {
                    cout << "Cart is empty, no items to be removed." << endl;
                }
                // Back to menu
                selection = menu();
            }
            // If user selects checkout/exit.
            if(selection == 3)
            {
                // Message if cart is empty.
                if(itemNumber == 0)
                {
                    cout << "Cart empty." << endl;
                }
                else
                {
                    grocList.print();
                }
       
            }
        }
    }
         cout << "Have a good day!" << endl;
    return 0;
}
