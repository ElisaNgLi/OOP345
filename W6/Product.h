/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/
#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H

#include <iostream>
#include <cstring>
#include "iProduct.h"

using namespace std;

namespace w6{
    
    class Product : public iProduct{
        string m_index;
        double m_cost;
        
        public:
        Product (string m_id = "/0", double m_price = 0);
        virtual double getPrice() const;
        virtual void display(ostream& os) const;
    };
}
#endif