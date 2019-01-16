/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/
#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H

#include <cstring>
#include "Product.h"

using namespace std;
namespace w6
{
    class TaxableProduct : public Product
    {
        char m_tax;
        enum tax {NONE, HST, PST};
        string m_num;
        double m_Cost;
    public:

        TaxableProduct(char m_taxes = '\0',string m_number = 0, double m_cost = 0);
        double getPrice() const ;
        void display(std::ostream&) const ;
    };


}
#endif