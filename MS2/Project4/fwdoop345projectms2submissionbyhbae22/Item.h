// Name: Hwisun Bae
// Seneca Student ID: 128-835-170
// Seneca email: hbae22@myseneca.ca
// Date of completion: 2018-11-17
#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Item{
    std::string m_name;
    std::string m_description;
    unsigned int m_serialNumber {0};
    unsigned int m_quantity {0};
    size_t m_widthField {1};
public:
    Item() = default;
    Item(std::string& record);
    const std::string& getName() const;
    const unsigned int getSerialNumber();
    const unsigned int getQuantity();
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
};

