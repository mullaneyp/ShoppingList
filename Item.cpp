/*******************************************************************************
 ** Author: Patrick Mullaney
 ** Description:  Implementation file for Item Class for Shopping List.
 ** Item stores item information and calculates price per unit of item.
 ** Date: 10/23/16
 *******************************************************************************/

#include "Item.hpp"
Item::Item(string n, string u, int q, long double p)
{
    name = n;
    unit = u;
    quantity = q;
    price = p;
}
string Item::getName()
{
    return name;
}
int Item::getQuantity()
{
    return quantity;
}
void Item::setQuantity(int q)
{
    quantity = q;
}
long double Item::getPrice()
{
    return price;
}
long double Item::extPrice()
{
    return quantity * price;
}
bool operator==(Item a, Item b)
{
    return a.getName()==b.getName();
}
void Item::print()
{
    cout << "Name: " << name << "\nUnit: " << unit << "\nQuantity: " << quantity << endl;
    cout << "Price per unit: $" << fixed << setprecision(2) << price << endl;
    cout << "Extended price: $" << fixed << setprecision(2) << extPrice() << endl;
}
