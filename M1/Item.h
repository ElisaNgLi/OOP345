// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 18, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <iomanip>
#include <functional>

using namespace std;

class Item{
    string m_name;
    string m_description;
    unsigned m_serialNumber;
    unsigned int m_quantity;
    unsigned int m_widthField;

    public:
    Item (string& record);
    const string& getName() const;
    const unsigned int getSerialNumber();
    const unsigned int getQuantity();
    void updateQuantity();
    void display(ostream& os, bool full) const;

};

#endif