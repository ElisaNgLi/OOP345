/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/

#ifndef TAXABLE_H
#define TAXABLE_H

#include "Product.h"
#include <cstring>

namespace w6 {
    

	class TaxableProduct : public Product {
		enum tax { NONE, HST, PST };
		char taxStatus;
        std::string p_Num;
		double p_Cost;
	public:
        TaxableProduct(char taxable = '\0', std::string m_num = 0, double m_price = 0.0);
		double getPrice() const;
		void display(std::ostream&) const;
	};
}

#endif // !TAXABLE_H

