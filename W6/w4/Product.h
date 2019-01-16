/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/

#ifndef PRODUCT_H
#define PRODUCT_H

#include <cstring> 
#include "iProduct.h"

namespace w6 {

	class Product : public iProduct {
        std::string p_Num;
		double p_Cost;
	public:
		Product(std::string m_num = "/0", double m_price = 0);
		virtual double getPrice() const;
		virtual void display(std::ostream&) const;
	};
}
#endif // !PRODUCT_H

