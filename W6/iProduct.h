/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/
// iProduct.h
#ifndef W6_IPRODUCT_H
#define W6_IPRODUCT_H
#include <fstream>
#include <iostream>

using namespace std;
namespace w6
{
    class iProduct
    {
    public:
        virtual double getPrice() const = 0;
        virtual void display(std::ostream&) const = 0;
    };

    ostream& operator<<(ostream&, const iProduct& );
    iProduct* readProduct(ifstream& fs);
}
#endif