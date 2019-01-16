/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/
// ProdUtil.h
#ifndef W6_PRODUTIL_H
#define W6_PRODUTIL_H

#include <iostream>
#include <fstream>
#include "iProduct.h"
#include "Product.h"


namespace w6
{
    std::ostream& operator<<(std::ostream&, const iProduct&);
    iProduct* readProduct(std::ifstream&);
}
#endif