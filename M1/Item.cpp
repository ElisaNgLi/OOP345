// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 18, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Item.h"
#include "Utilities.h"

using namespace std;

Item::Item(string& record){
    bool more = true;
    size_t next_pos = -1;

    Utilities m_Util;

    if (more){
        m_name = m_Util.extractToken(record, next_pos, more);
        m_serialNumber = stoi(m_Util.extractToken(record, next_pos, more));
        m_quantity = stoi(m_Util.extractToken(record, next_pos, more));
        m_description = m_Util.extractToken(record, next_pos, more);
    }

    m_widthField = 0;

    if(m_widthField < (m_Util.getFieldWidth())){
        m_widthField = static_cast<int> (m_Util.getFieldWidth());
    }
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
    if (full){
        string m_empty = "         ";
        os << left << setw(13) << m_name;
        os << "[" << right << setw(6) << setfill('0') << m_serialNumber << "] " << setfill(' ');
        os << "Quantity: " << left << setw(4) << m_quantity;
        os << m_empty << "Description: " << m_description << "\n";
    }else{
        os << left << setw(13) << m_name;
        os << "[" << right << setw(6) << setfill('0') << m_serialNumber << "]\n" << setfill(' ');
    }
}