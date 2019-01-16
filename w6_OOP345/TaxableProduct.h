// Workshop 6 - STL Containers
// TaxableProduct.h
// Author: Sean Kevin Surjanto
// ID: 148057177

#ifndef TAXABLE_H
#define TAXABLE_H

#include "Product.h"

static double rate[3] = { 0, 1.13, 1.08 };

namespace w6 {

	class TaxableProduct : public Product {
		enum tax { NONE, HST, PST };
		char taxStatus;
		int pNum;
		double pCost;
	public:
		TaxableProduct(char taxable = '\0', int num = 0, double price = 0.0);
		double getPrice() const;
		void display(std::ostream&) const;
	};
}

#endif // !TAXABLE_H

