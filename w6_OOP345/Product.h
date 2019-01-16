// Workshop 6 - STL Containers
// Product.h
// Author: Sean Kevin Surjanto
// ID: 148057177

#ifndef PRODUCT_H
#define PRODUCT_H

#include "iProduct.h"

namespace w6 {

	class Product : public iProduct {
		int pNum;
		double pCost;
	public:
		Product(int num = 0, double price = 0);
		virtual double getPrice() const;
		virtual void display(std::ostream&) const;
	};
}
#endif // !PRODUCT_H

