// Name: Hwisun Bae
// Seneca Student ID: 128-835-170
// Seneca email: hbae22@myseneca.ca
// Date of completion: 2018-11-22
#pragma once

#include <iostream>
#include <string>
#include "Utilities.h"
#include "Item.h"

using namespace std;

class Item;

struct ItemInfo {
    std::string m_itemName;
    unsigned int m_serialNumber = 0;
    bool m_fillState = false;

    ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {
    std::string m_name;
    std::string m_product;
    unsigned int m_cntItem {0};
    ItemInfo** m_lstItem {nullptr};
    static size_t m_widthField;
public:
    CustomerOrder() = default;
    CustomerOrder(string& );
    CustomerOrder(CustomerOrder& ) { throw "ERROR: Cannot make copies.";};
    CustomerOrder& operator=(CustomerOrder&) = delete;
    CustomerOrder(CustomerOrder &&);                //move constructor
    CustomerOrder& operator=(CustomerOrder &&);     //move assignment operator
    ~CustomerOrder();
    bool getItemFillState(std::string) const;
    bool getOrderFillState() const;
    void fillItem(Item& item, std::ostream&);
    void display(std::ostream&) const;
};
