// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 24, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <iostream>
#include <string>

class Item;

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;
	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {

private:
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem;
	static size_t m_widthField;

public:
	CustomerOrder();
	CustomerOrder(const std::string& record);
	~CustomerOrder();

	CustomerOrder(CustomerOrder&) { throw "ERROR: Cannot make copies."; };
	CustomerOrder(CustomerOrder&&) noexcept;
	CustomerOrder& operator=(CustomerOrder&&);

	bool getOrderFillState() const;
	bool getItemFillState(std::string) const;
	void fillItem(Item&, std::ostream&);
	void display(std::ostream&) const;

};
