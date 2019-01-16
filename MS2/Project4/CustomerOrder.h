

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

class CustomerOrder
{
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem;
	static size_t m_widthField;

public:
	CustomerOrder();
	CustomerOrder(std::string&);
	~CustomerOrder();

	//Object is not allowed to be copied
	CustomerOrder(CustomerOrder&) { throw "ERROR:  Copy is not allows"; };			//should throw an exception if called
	CustomerOrder& operator=(CustomerOrder&) = delete;

	//Object move functionality
	CustomerOrder(CustomerOrder&&);
	CustomerOrder& operator=(CustomerOrder&&);

	bool getOrderFillState() const;								//Returns true if order completely filled, false otherwise
	bool getItemFillState(std::string) const;						//Returns true if the given item has been filled
	void fillItem(Item&, std::ostream&);					//Fills the customer order item if the inventory on Item is available

	void display(std::ostream&) const;							//Displays the details of the CustomerOrder to the ostream object provided

};
