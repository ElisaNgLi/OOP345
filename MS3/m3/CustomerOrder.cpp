// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 24, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include <iostream>
#include <string>
#include <iomanip>
#include "CustomerOrder.h"
#include "Item.h"
#include "Utilities.h"

using namespace std;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() {
	m_cntItem = 0u;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(const string& str) {
	Utilities m_util;
	bool more = true;
	size_t next_pos = 0u;

	m_name = m_util.extractToken(str, next_pos, more);
	m_product = m_util.extractToken(str, next_pos, more);
	m_cntItem = 0u;

	size_t start_pos = next_pos;
	while (more) {
		m_util.extractToken(str, next_pos, more);
		++m_cntItem;
	}

	m_lstItem = new ItemInfo*[m_cntItem];
	
	more = true;
	
	// extract tokens into array
	for (size_t i = 0u; i < m_cntItem; ++i) {
		m_lstItem[i] = new ItemInfo(m_util.extractToken(str, start_pos, more));
	}

	if (m_util.getFieldWidth() > m_widthField)
		m_widthField = m_util.getFieldWidth();

}


CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
	m_lstItem = nullptr;
	*this = move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {
	if ( this != &src) {
		this->m_name = src.m_name;
		this->m_product = src.m_product;

	
		if (m_lstItem)
			for (unsigned int i = 0; i < m_cntItem; i++)
				delete this->m_lstItem[i];
		delete[] this->m_lstItem;

		this->m_cntItem = src.m_cntItem;
		this->m_lstItem = src.m_lstItem;

		src.m_lstItem = nullptr;
	}

	return *this;
}


CustomerOrder::~CustomerOrder() {
	m_cntItem = 0;
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::getItemFillState(string str) const {
	
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (m_lstItem[i]->m_itemName == str)
			if (!m_lstItem[i]->m_fillState) {
				return false;
				break;
			}
	}

	return true;
}

bool CustomerOrder::getOrderFillState() const {
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (!m_lstItem[i]->m_fillState)
			return false;
	}

	return true;
}

void CustomerOrder::fillItem(Item& item, ostream& os) {

	for (unsigned int i = 0; i < m_cntItem; ++i) {
	
		if (m_lstItem[i]->m_itemName == item.getName() && !m_lstItem[i]->m_fillState) {
			if (item.getQuantity() > 0) {
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				item.updateQuantity();
				m_lstItem[i]->m_fillState = true;
				os << "Filled ";
			}
			else {
				os << "Unable to fill ";
			}

			os << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << endl;
			return;
		}
	}

}

void CustomerOrder::display(ostream& os) const {
	os << m_name << " - " << m_product << endl;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		os << "[" << setw(6) << setfill('0') << right << m_lstItem[i]->m_serialNumber
			<< setfill(' ') << "] " << setw(m_widthField) << left << m_lstItem[i]->m_itemName
			<< " - " << (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING") << endl;
	}
}

