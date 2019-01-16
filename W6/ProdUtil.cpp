/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/

#include <sstream>
#include "ProdUtil.h"
#include "TaxableProduct.h"
using namespace std;

namespace w6{
    std::ostream& operator<<(std::ostream& os, const iProduct& prod){
        prod.display(os);
        os << endl;
        return os;
    }

    iProduct* readProduct(std::ifstream& fs){
        string No_tmp;
        double cost_tmp;
        char tax_tmp = '\0';
        
        string oneLine;
        getline(fs, oneLine);
        if (oneLine == "") {
            return nullptr;
        }
        stringstream oneLinestream(oneLine);
        oneLinestream >> No_tmp >> cost_tmp >> tax_tmp;
        
        if (tax_tmp != '\0') {
            if (tax_tmp == 'H' || tax_tmp == 'P') {
                return new TaxableProduct(tax_tmp, No_tmp, cost_tmp);
            }
            else {
                
                throw "Unrecognizable Tax Code!";
            }
        }
        else {
            return new Product(No_tmp, cost_tmp);
        }
    }
}