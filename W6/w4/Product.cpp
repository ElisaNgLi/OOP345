/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/
#include <iomanip>
#include "Product.h"


namespace w6 {

	Product::Product(std::string m_num, double m_price) {
		p_Num = m_num;
		p_Cost = m_price;
	}

	double Product::getPrice() const {
		return p_Cost;
	}

	void Product::display(std::ostream& os) const {
		if (p_Num != "/0" && p_Cost != 0)
			os << std::setw(16) << p_Num << std::setw(16) << p_Cost;
	}

}
