// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 24, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.




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
	size_t next_pos = -1;

	std::vector<std::string> m_item;
	Utilities m_util;

	if (more) {
		m_name = m_util.extractToken(str, next_pos, more);
		if (more) {
			m_product = m_util.extractToken(str, next_pos, more);
			while (more) {
				m_item.push_back(m_util.extractToken(str, next_pos, more));
				m_cntItem++;
			}
		}
	}
	 
	
	if (m_widthField < m_util.getFieldWidth()) {
		m_widthField = static_cast<int>(m_util.getFieldWidth());
	}

	m_lstItem = new ItemInfo*[m_cntItem];

	for (size_t i = 0; i < m_item.size(); i++) {
		m_lstItem[i] = new ItemInfo(m_item[i]);
	}
}

CustomerOrder::~CustomerOrder() {
	m_cntItem = 0;
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(CustomerOrder&& m_order) {
	m_cntItem = 0;
	m_lstItem = nullptr;
	*this = std::move(m_order);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& m_order) {
	if (this != &m_order) {

		delete[] m_lstItem;
		m_lstItem = nullptr;


		m_name = m_order.m_name;
		m_product = m_order.m_product;
		m_cntItem = m_order.m_cntItem;
		m_lstItem = new ItemInfo*[m_order.m_cntItem];
		for (size_t i = 0; i < m_cntItem; i++) {
			m_lstItem[i] = new ItemInfo(m_order.m_lstItem[i]->m_itemName);
		}


		m_order.m_name = "";
		m_order.m_product = "";
		delete[] m_order.m_lstItem;
		m_order.m_lstItem = nullptr;
		m_order.m_cntItem = 0;
	}
	return *this;
}

bool CustomerOrder::getOrderFillState() const {
	int what = 0;
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_fillState == false) {
			what += 1;
		}
	}
	if (what > 0) {
		return false;
	}
	return true;
}

bool CustomerOrder::getItemFillState(std::string str) const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == str) {
			return true;
		}
	}
	return false;
}


void CustomerOrder::fillItem(Item& m_item, std::ostream& os) {

	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == m_item.getName()) {
			m_lstItem[i]->m_fillState = true;
			os << "Filled " << m_name << ", " << m_product << "[" << m_item.getName() << "]" << endl;
		}
		if (m_lstItem[i] != NULL && m_item.getQuantity() == 0) {
			m_lstItem[i]->m_fillState = false;
			os << "Unable to fill " << m_name << ", " << m_product << "[" << m_item.getName() << "]" << endl;
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
