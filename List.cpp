/*******************************************************************************
 ** Author: Patrick Mullaney
 ** Description:  Implementation file for List Class for Shopping List.
 ** List stores pointers to Item objects in an array.
 ** Date: 10/23/16
 *******************************************************************************/

#include "List.hpp"
#include <iostream>
#include <string>

using namespace std;

List::List()
{   // Initialize listSize to 4.
    listSize = 4;
    
    // Initialize itemNumber to 0.
    itemNumber = 0;
    
    // Create array of pointers to Items.
    itemPtr = new Item*[listSize];
}
int List::getSize()
{
    return listSize;
}
void List::setSize(int s)
{
    listSize = s;
}
int List::getNumber()
{
    return itemNumber;
}
void List::setNumber(int n)
{
    itemNumber = n;
}
Item** List::getArray()
{
    return itemPtr;
}
/**********************************************************************************************
** createItem prompts the user for name, unit, quantity, and price for a new Item, then creates
** a pointer to that Item.
***********************************************************************************************/
Item* List::createItem()
{
    string name;
    string unit;
    int quantity;
    double price;
    
    cout << "Enter name." << endl;
    getline(cin, name);
    cout << "Enter unit." << endl;
    getline(cin, unit);
    cout << "Enter quantity." << endl;
    cin >> quantity;
    while(quantity < 0 )
    {
        cout << "Please enter a number greater than 0. " << endl;
        cin >> quantity;
        cin.clear();
        cin.ignore();
    }
    cout << "Enter price." << endl;
    cin >> price;
    while(price < 0 )
    {
        cout << "Please enter a number greater than 0. " << endl;
        cin >> price;
        cin.clear();
        cin.ignore();
    }
    
    // Allocate memory for new Item
    newItem = new Item(name, unit, quantity, price);
    return newItem;
}
void List::addItem(Item* newItem, int itemN)
{
        itemPtr[itemN] = newItem;
        itemNumber++;
        setNumber(itemNumber);
}
/**************************************************************************************
** removeItem removes an Item from the array by looping through until an item is found.
** Once a match is found, the pointer to the Item is removed and array shifted over.  
** itemNumber is decreased and updated.  User is notified.
****************************************************************************************/
void List::removeItem(string n)
{
    string name = n;
    int match = -1;
    for(int i = 0; i < itemNumber; i++)
    {  match = -1;
        
        if(itemPtr[i]->getName() == name)
        {
            match = i;
        }
        //  If match found.
        if(match == i)
        {
            cout << "Item removed: " << itemPtr[i]->getName() << endl;
            delete itemPtr[i];
            for(int j = i; j < itemNumber; j++)
            {
                itemPtr[j] = itemPtr[j+1];
            }
            itemNumber--;
            break;
        }
    }
    if(match == -1)
    {
        cout << "Item not in cart." << endl;
    }
    
    setNumber(itemNumber);
}
/********************************************************************************************
** addList resizes the itemPtr array.  Once itemNumber equals size of the array in main,
** addList creates a new temp item array with a larger size, copies the contents of itemPtr
** and deletes the old array.
*********************************************************************************************/
void List::addList(List *l, int &listSize)
{
    listSize *= 2;
    //cout << "list size " << listSize << endl;
    setSize(listSize);
    
    Item** temp = new Item*[listSize];
    for(int i = 0; i < listSize; i++)
    {
        temp[i] = itemPtr[i];
    }
    delete [] itemPtr;
    itemPtr = temp;
    
}
/***********************************************************************************
 ** listPrice calculates the price for all items in the list by getting the extended
 ** price for all items in the list and then calculating the sum of thos items.
 ***********************************************************************************/
long double List::listPrice()
{
    long double total = 0;
    
    for(int i = 0; i < itemNumber; i++)
    {
            total += itemPtr[i]->extPrice();
    }
    return total;
}
void List::print()
{   cout << "Final list: " << endl;
    for(int i = 0; i < itemNumber; i++)
    {
        //cout << "item# " << i << endl;
        if(itemPtr[i])
        {
            itemPtr[i]->print();
        }
    }
    cout << "Total: $" << fixed << setprecision(2) << listPrice() << endl;
}
List::~List()
{
    for(int i = 0; i < itemNumber; i++)
    {
        if(itemPtr[i])
        {
            delete itemPtr[i];
        }
    }
    delete [] itemPtr;
}