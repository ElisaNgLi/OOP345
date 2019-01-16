// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 24, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iomanip>
#include <functional>
#include "Item.h"
#include "Utilities.h"

using namespace std;


Item::Item(const string& record) {
	bool more = true;
	size_t next_pos = 0;
	size_t i = 0;
	Utilities m_util;
	m_util.setFieldWidth(m_widthField);
	while (more && i < 4) {
		if (i == 0) m_name = m_util.extractToken(record, next_pos, more);
		else if (i == 1) m_serialNumber = (unsigned)stoi(m_util.extractToken(record, next_pos, more));
		else if (i == 2) m_quantity = (unsigned int)stoi(m_util.extractToken(record, next_pos, more));
		else m_description = m_util.extractToken(record, next_pos, more);
		i++;
	}

}

const string& Item::getName() const {
	return m_name;
}


const unsigned int Item::getSerialNumber() {
	int number = m_serialNumber;
	m_serialNumber += 1;
	return number;
}

const unsigned int Item::getQuantity() {
	return m_quantity;
}

void Item::updateQuantity() {
	if (m_quantity > 0) {
		m_quantity -= 1;
	}
}

void Item::display(ostream& os, bool full) const {

	if (full) {
		string empty = "         ";
		os << left << setw(13) << m_name;
		os << "[" << right << setw(6) << setfill('0') << m_serialNumber << "] " << setfill(' ');
		os << "Quantity: " << left << setw(4) << m_quantity;
		os << empty << "Description: " << m_description << "\n";
	}
	if (!full) {
		os << left << setw(13) << m_name;
		os << "[" << right << setw(6) << setfill('0') << m_serialNumber << "]\n" << setfill(' ');

	}
}

