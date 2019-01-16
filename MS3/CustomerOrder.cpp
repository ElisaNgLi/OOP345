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

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() {
	m_cntItem = 0u;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(std::string& str) {
	
    Utilities util;
    bool more = true;
    size_t next_pos = 0u;
    
    m_name = util.extractToken(str, next_pos, more);
    m_product = util.extractToken(str, next_pos, more);
    m_cntItem = 0u;

    
    size_t start_pos = next_pos;
  
    while (more) {
        util.extractToken(str, next_pos, more);
        ++m_cntItem;
    }

     m_lstItem = new ItemInfo*[m_cntItem];
    
    more = true; 
    // extract tokens into array
    for (size_t i = 0u; i < m_cntItem; ++i) {
        m_lstItem[i] = new ItemInfo(util.extractToken(str, start_pos, more));
    }

    if (util.getFieldWidth() > m_widthField)
        m_widthField = util.getFieldWidth();
}

CustomerOrder::~CustomerOrder() {
	if (m_lstItem)
        for (unsigned int i = 0; i < m_cntItem; ++i){
            delete m_lstItem[i];
		}
    delete [] m_lstItem;

	// m_cntItem = 0;
	// delete[] m_lstItem;
	// m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(CustomerOrder&& m_order) noexcept{
	m_lstItem = nullptr;
	*this = std::move(m_order);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {


	if (this != &src) {
        this->m_name = src.m_name;
        this->m_product = src.m_product;
        
        // delete the pointers in the array
        if (m_lstItem)
            for (unsigned int i = 0; i < m_cntItem; i++)
                delete this->m_lstItem[i];
        delete [] this->m_lstItem;
        
        this->m_cntItem = src.m_cntItem;
        this-> m_lstItem= src.m_lstItem;

        src.m_lstItem = nullptr;
    }

    return *this;
}

bool CustomerOrder::getOrderFillState() const {
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (!m_lstItem[i]->m_fillState) {
			return false;
		}
	}
	return true;
}

bool CustomerOrder::getItemFillState(std::string str) const {
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == str) {
			if (!m_lstItem[i] -> m_fillState){
				return false;
				break;
			}
		}
	}
	return true;
}


void CustomerOrder::fillItem(Item& item, std::ostream& os) {


	for (unsigned int i = 0; i < m_cntItem; ++i) {
       
        if (m_lstItem[i]->m_itemName == item.getName() && !m_lstItem[i]->m_fillState) {
            if (item.getQuantity() > 0) {
                m_lstItem[i]->m_serialNumber = item.getSerialNumber();
                item.updateQuantity();
                m_lstItem[i]->m_fillState = true;
                os << "Filled ";
            } else {
                os << "Unable to fill ";
            }
            
            os << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
            return;
        }
    }
}

void CustomerOrder::display(std::ostream& os) const {

	os << m_name << " - " << m_product << std::endl;
    for (unsigned int i = 0; i < m_cntItem; i++) {
        os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber ;
         os  << std::setfill(' ') << "] " << std::setw(m_widthField) << std::left << m_lstItem[i]->m_itemName;
          os << " - " << (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING") << std::endl;
    }
}
