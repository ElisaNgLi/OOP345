// Workshop 6 - STL Containers
// Product.cpp
// Author: Sean Kevin Surjanto
// ID: 148057177

#include "Product.h"
#include <iomanip>

namespace w6 {

	Product::Product(int num, double price) {
		pNum = num;
		pCost = price;
	}

	double Product::getPrice() const {
		return pCost;
	}

	void Product::display(std::ostream& os) const {
		if (pNum != 0 && pCost != 0)
			os << pNum << std::setw(15) << pCost << std::endl;
	}

}