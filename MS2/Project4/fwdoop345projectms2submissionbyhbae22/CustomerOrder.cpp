// Name: Hwisun Bae
// Seneca Student ID: 128-835-170
// Seneca email: hbae22@myseneca.ca
// Date of completion: 2018-11-22

#include "CustomerOrder.h"
#include <vector>

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder(std::string& str){
    bool more = true;
    size_t next_pos = -1;
    
    std::vector<std::string> items;
    Utilities util;

    if (more) {
        m_name = util.extractToken(str, next_pos, more);
        m_product = util.extractToken(str, next_pos, more);
        while (more) {
            items.push_back(util.extractToken(str, next_pos, more));
            m_cntItem++;
        }
    }
    // set widthfield of util upto m_widthField
    if (m_widthField < util.getfieldWidth()) {
        m_widthField = static_cast<int>(util.getfieldWidth());
    }
    m_lstItem = new ItemInfo *[m_cntItem];

    for (size_t i = 0; i < items.size(); i++) {
        m_lstItem[i] = new ItemInfo(items[i]);
    }
}
CustomerOrder::CustomerOrder(CustomerOrder &&obj){
    m_cntItem = 0;
    m_lstItem = nullptr;
    *this = std::move(obj);
} //move constructor
CustomerOrder& CustomerOrder::operator=(CustomerOrder &&obj){
    if (this != &obj) {

        delete[] m_lstItem;
        m_lstItem = nullptr;

        m_name = obj.m_name;
        m_product = obj.m_product;
        m_cntItem = obj.m_cntItem;
        m_lstItem = new ItemInfo*[obj.m_cntItem];
        for (size_t i = 0; i < m_cntItem; i++) {
            m_lstItem[i] = new ItemInfo(obj.m_lstItem[i]->m_itemName);
        }

        obj.m_name = "";
        obj.m_product = "";
        delete[] obj.m_lstItem;
        obj.m_lstItem = nullptr;
        obj.m_cntItem = 0;
    }
    return *this;
} //move assignment operator
CustomerOrder::~CustomerOrder(){
    m_cntItem = 0;
    delete[] m_lstItem;
    m_lstItem = nullptr;
}
bool CustomerOrder::getItemFillState(std::string str) const{
    bool flag = true;
    for (size_t i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_itemName == str) {
            return flag;
        }
    }
    flag = false;
    return flag;
}
bool CustomerOrder::getOrderFillState() const{
    int check = 0;
    bool flag = false;
    for (size_t i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_fillState == flag) {
            check += 1;
        }
    }
    if (check > 0) {
        return flag;
    }
    flag = true;
    return flag;
}
void CustomerOrder::fillItem(Item& item, std::ostream& os){
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
void CustomerOrder::display(std::ostream& os) const{
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
