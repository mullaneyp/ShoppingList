/*******************************************************************************
 ** Author: Patrick Mullaney
 ** Description:  Implementation file for Item Class for Shopping List.
 ** Item stores item information and calculates price per unit of item.
 ** Date: 10/23/16
 *******************************************************************************/

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Item{
    
private:
    string name, unit;
    int quantity;
    long double price;
    
public:
    //Constructor
    Item(string, string, int, long double);
    
    //Get methods
    string getName();
    int getQuantity();
    void setQuantity(int);
    long double getPrice();
    
    // Calculates price based on quantity * price per unit.
    long double extPrice();
    
    // Overload equality operator to check for duplicates in list.
    bool friend operator==(Item a, Item b);
    
    // Print Item.
    void print();
    
};

#endif /* Item_hpp */
