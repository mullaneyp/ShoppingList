/*******************************************************************************
 ** Author: Patrick Mullaney
 ** Description:  Menu for Shopping List.
 ** Date: 10/23/16
 *******************************************************************************/

#include "Menu.hpp"
#include <iostream>

using namespace std;

int startMenu()
{
    int start;
    cout << "Main Menu: " << endl;
    cout << "1. Create list. \n2. Exit" << endl;
    cin >> start;
    cin.clear();
    cin.ignore();
    while((start < 1) || (start > 2))
    {
        cout << "Please enter a choice between 1 and 2." << endl;
        cin >> start;
        cin.clear();
        cin.ignore();
    }
    return start;
}
int menu()
{
    int selection;
    // Menu
    cout << "Item Menu" << endl; 
    cout << "Please make a selection: " << endl;
    cout << "1. Add item.  \n2. Remove item.  \n3. Checkout/Exit." << endl;
    cin >> selection;
    cin.clear();
    cin.ignore();
    
    while((selection < 1) || (selection > 3))
    {
        cout << "Please enter a choice between 1 and 3." << endl;
        cin >> selection;
    }
    return selection;
}