/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/
#include <iomanip>
#include "Product.h"

using namespace std;

namespace w6{

    Product::Product (string m_id , double m_price){
        m_index = m_id;
        m_cost = m_price;
    }

    double Product::getPrice() const {
        return m_cost;
    }

    void Product::display(ostream& os) const{
        if (m_index != "/0" && m_cost != 0)
        os << setw(16) << m_index <<  setw(16) << m_cost;
    }

}