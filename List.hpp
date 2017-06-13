/*******************************************************************************
 ** Author: Patrick Mullaney
 ** Description:  Header file for List Class for Shopping List.
 ** List stores pointers to Item objects in an array.
 ** Date: 10/23/16
 *******************************************************************************/

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>
#include "Item.hpp"

class List {
    
private:
    int listSize, itemNumber;
    Item** itemPtr;
    Item* newItem;
    
    public:
    // Constructor.
    List();
    
    // Get and set for methods for size and itemNumber.
    int getSize();
    void setSize(int);
    int getNumber();
    void setNumber(int);
    Item** getArray();
    
    // Creates a pointer to an Item.
    Item* createItem();
    
    // Adds an Item to list.
    void addItem(Item*, int);
    
    // addList resizes array by incrementing listSize then copying array.
    void addList(List[], int&);
    
    // Removes an item.
    void removeItem(string);
    
    // Returns price for all items in list.
    long double listPrice();
 
    // Displays shopping list to user.
    void print();
    
    // Deconstructor.
    ~List();
};


#endif /* List_hpp */
