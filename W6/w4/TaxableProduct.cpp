/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/

#include "TaxableProduct.h"
#include <iomanip>

namespace w6 {
	//static class variable
    static double rate[3] = { 0, 1.13, 1.08 }; 
    
	TaxableProduct::TaxableProduct(char taxable, std::string m_num, double m_price) {
		taxStatus = taxable;
		p_Num = m_num;
		p_Cost = m_price;
	}

	double TaxableProduct::getPrice() const {
		if (taxStatus == 'H') {
			return p_Cost * rate[tax::HST];
		}
		else if (taxStatus == 'P') {
			return p_Cost * rate[tax::PST];
		}
		else {
			return p_Cost * rate[tax::NONE];
		}
	}

	void TaxableProduct::display(std::ostream& os) const {
		if (p_Num != "/0") {
			if (taxStatus == 'H') {
                os << std::setw(16)<< p_Num << std::setw(16) << p_Cost << std::setw(4) << "HST";
			}
			if (taxStatus == 'P') {
                os << std::setw(16)<< p_Num << std::setw(16) << p_Cost << std::setw(4) << "PST" ;
			}
		}
	}
}
