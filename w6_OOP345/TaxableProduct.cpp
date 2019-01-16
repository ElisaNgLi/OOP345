// Workshop 6 - STL Containers
// TaxableProduct.cpp
// Author: Sean Kevin Surjanto
// ID: 148057177

#include "TaxableProduct.h"
#include <iomanip>

namespace w6 {

	TaxableProduct::TaxableProduct(char taxable, int num, double price) {
		taxStatus = taxable;
		pNum = num;
		pCost = price;
	}

	double TaxableProduct::getPrice() const {
		if (taxStatus == 'H') {
			return pCost * rate[tax::HST];
		}
		else if (taxStatus == 'P') {
			return pCost * rate[tax::PST];
		}
		else {
			return pCost * rate[tax::NONE];
		}
	}

	void TaxableProduct::display(std::ostream& os) const {
		if (pNum != 0) {
			if (taxStatus == 'H') {
				os << pNum << std::setw(15) << pCost << std::setw(10) << "HST" << std::endl;
			}
			if (taxStatus == 'P') {
				os << pNum << std::setw(15) << pCost << std::setw(10) << "PST" << std::endl;
			}
		}
	}
}