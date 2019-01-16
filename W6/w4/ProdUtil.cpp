/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/

#include <sstream>
#include "TaxableProduct.h"
#include "ProdUtil.h"

namespace w6 {
    std::ostream& operator<<(std::ostream& os, const iProduct& product) {
        product.display(os);
        os << std::endl;
        return os;
    }
    
    iProduct* readProduct(std::ifstream& fs) {
        std::string No_tmp;
        double price_tmp;
        char tax_tmp = '\0';
        
        std::string oneLine;
        getline(fs, oneLine);
        if (oneLine == "") {
            return nullptr;
        }
        std::stringstream oneLinestream(oneLine);
        oneLinestream >> No_tmp >> price_tmp >> tax_tmp;
        
        if (tax_tmp != '\0') {
            if (tax_tmp == 'H' || tax_tmp == 'P') {
                return new TaxableProduct(tax_tmp, No_tmp, price_tmp);
            }
            else {
                std::string err = "Unrecognizable Tax Code!";
                throw err;
            }
        }
        else {
            return new Product(No_tmp, price_tmp);
        }
    }
}

