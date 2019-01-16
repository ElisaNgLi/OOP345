// Name: Hwisun Bae
// Seneca Student ID: 128-835-170
// Seneca email: hbae22@myseneca.ca
// Date of completion: 2018-11-17
#include "Item.h"
#include "Utilities.h"
#include <iomanip>

Item::Item(std::string& record) : Item(){
    Utilities u;
    size_t pos = -1;
    bool more = true;

    if(more) {
        m_name = u.extractToken(record, pos, more);
    }
    if(more) {
        m_serialNumber = std::stoi(u.extractToken(record, pos, more));
    }
    if(more) {
        m_quantity = std::stoi(u.extractToken(record, pos, more));
    }
    if(more) {
        m_description = u.extractToken(record, pos, more);
    }
    if(m_widthField < (u.getfieldWidth())){
        m_widthField = u.getfieldWidth();
    }
}

const std::string& Item::getName() const{
    return m_name;
}
const unsigned int Item::getSerialNumber(){
    return m_serialNumber++;
}
const unsigned int Item::getQuantity(){
    return m_quantity;
}
void Item::updateQuantity(){
    m_quantity--;
    if (m_quantity < 0){
        m_quantity = 0;
    }
}
void Item::display(std::ostream& os, bool full) const{
    if (full) {
        std::string empty = "         ";
        os << std::left << std::setw(13) << m_name;
        os << "[" << std::right << std::setw(6) << std::setfill('0') << m_serialNumber << "] " << std::setfill(' ');
        os << "Quantity: " << std::left << std::setw(4) << m_quantity;
        os << empty << "Description: " << m_description << "\n";
    }
    if (!full) {
        os << std::left << std::setw(13) << m_name;
        os << "[" << std::right << std::setw(6) << std::setfill('0') << m_serialNumber << "]\n" << std::setfill(' ');
    }
}
