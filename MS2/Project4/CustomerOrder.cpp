

#include <vector>
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Item.h"

using namespace std;

size_t CustomerOrder::m_widthField = 1;

CustomerOrder::CustomerOrder() {
	m_cntItem = 0;
	m_lstItem = nullptr;
	m_widthField = 0;
}

CustomerOrder::CustomerOrder(std::string& str) {
	bool more = true;
	//declare next_pos to start from 0
	size_t next_pos = -1;

	//save data temporary to move data to lstItem
	std::vector<std::string> items;
	Utilities u;

	// get the token which is the string start from position and length is second argument to update customerorders
	if (more) {
		m_name = u.extractToken(str, next_pos, more);
		if (more) {
			m_product = u.extractToken(str, next_pos, more);
			while (more) {
				items.push_back(u.extractToken(str, next_pos, more));
				m_cntItem++;
			}
		}
	}
	 
	//store utilities fieldwidth if it's bigger
	if (m_widthField < u.getFieldWidth()) {
		m_widthField = static_cast<int>(u.getFieldWidth());
	}

	// allocate ItemInfo pointer
	m_lstItem = new ItemInfo*[m_cntItem];

	//alocate iteminfo with items.size
	for (size_t i = 0; i < items.size(); i++) {
		m_lstItem[i] = new ItemInfo(items[i]);
	}
}

CustomerOrder::~CustomerOrder() {
	m_cntItem = 0;
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(CustomerOrder&& order) {
	m_cntItem = 0;
	m_lstItem = nullptr;
	*this = std::move(order);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) {
	if (this != &order) {

		delete[] m_lstItem;
		m_lstItem = nullptr;


		m_name = order.m_name;
		m_product = order.m_product;
		m_cntItem = order.m_cntItem;
		m_lstItem = new ItemInfo*[order.m_cntItem];
		for (size_t i = 0; i < m_cntItem; i++) {
			m_lstItem[i] = new ItemInfo(order.m_lstItem[i]->m_itemName);
		}


		order.m_name = "";
		order.m_product = "";
		delete[] order.m_lstItem;
		order.m_lstItem = nullptr;
		order.m_cntItem = 0;
	}
	return *this;
}

//returns true if all the items in the order have been filled; false otherwise
bool CustomerOrder::getOrderFillState() const {
	int check = 0;
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_fillState == false) {
			check += 1;
		}
	}
	if (check > 0) {
		return false;
	}
	return true;
}

//returns the ItemInfo::m_fillState of the item specified as a parameter.If the item doesn’t exist in the order, return true
bool CustomerOrder::getItemFillState(std::string str) const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == str) {
			/*return m_lstItem[i]->m_fillState;*/
			return true;
		}
	}
	return false;
}

// fills the item in the current order that corresponds to the item passed into the function(the parameter item represents what is 	available in the inventory)
void CustomerOrder::fillItem(Item& item, std::ostream& os) {

	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == item.getName()) {
			m_lstItem[i]->m_fillState = true;
			os << "Filled " << m_name << ", " << m_product << "[" << item.getName() << "]" << endl;
		}
		if (m_lstItem[i] != NULL && item.getQuantity() == 0) {
			m_lstItem[i]->m_fillState = false;
			os << "Unable to fill " << m_name << ", " << m_product << "[" << item.getName() << "]" << endl;
		}
	}
}

void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - ";
	os << m_product << endl;
	
	for (size_t i = 0; i < m_cntItem; i++) {
		m_lstItem[i]->m_itemName.length();
		os << "[" << right << setfill('0') << setw(6) << m_lstItem[i]->m_serialNumber << "] ";
		if (m_lstItem[i]->m_itemName.length() == 3) {
			os << m_lstItem[i]->m_itemName << setfill(' ') << right << setw(23) << " - MISSING" << endl;
		}
		else if (m_lstItem[i]->m_itemName.length() == 12) {
			os << m_lstItem[i]->m_itemName << setfill(' ') << right << setw(14) << " - MISSING" << endl;
		}
		else {
			os << m_lstItem[i]->m_itemName << setfill(' ') << right << setw(20) << " - MISSING" << endl;
		}
	}
}
