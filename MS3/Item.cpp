// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 18, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Item.h"
#include "Utilities.h"
#include <iomanip>

using namespace std;

Item::Item(string& record){

    Utilities util;
    // necessary variables for Utilities
    bool more = true;
    size_t next_pos = 0u;

    m_name = util.extractToken(record, next_pos, more);
    m_serialNumber = std::stoi(util.extractToken(record, next_pos, more));
    m_quantity = std::stoi(util.extractToken(record, next_pos, more));
    m_widthField = util.getFieldWidth();
    m_description = util.extractToken(record, next_pos, more);

    // bool more = true;
	// size_t next_pos = 0;
	// size_t i = 0;
	// Utilities u;
	// u.setFieldWidth(m_widthField);
	// while (more && i < 4) {
	// 	if (i == 0) m_name = u.extractToken(record, next_pos, more);
	// 	else if (i == 1) m_serialNumber = (unsigned)std::stoi(u.extractToken(record, next_pos, more));
	// 	else if (i == 2) m_quantity = (unsigned int)std::stoi(u.extractToken(record, next_pos, more));
	// 	else m_description = u.extractToken(record, next_pos, more);
	// 	i++;
	// }
}


const string& Item::getName() const{
    return m_name;
}

const unsigned int Item::getSerialNumber(){ 
    int num = m_serialNumber;
    m_serialNumber += 1;
    return num;
}

const unsigned int Item::getQuantity(){
    return m_quantity;
}

void Item::updateQuantity(){
    if(m_quantity > 0){
        m_quantity -= 1;
    }    
}

void Item::display(ostream& os, bool full) const{
    string m_empty = "        ";
    os << std::setw(m_widthField) << std::left << setw(13)<< m_name << "[" ;
    os   << std::setw(6) << std::right << std::setfill('0') << m_serialNumber << std::setfill(' ') << "]";
    if (full) {
        os << " Quantity: " << std::setw(m_widthField) << std::left << setw(4) << m_quantity << m_empty << " Description: " << m_description;
    }
    os << std::endl;
    
}