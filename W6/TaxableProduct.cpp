
#include <iomanip>
#include "TaxableProduct.h"

using namespace std;

namespace w6{

    //static class variable
    static double rate[3] = {0, 1.13, 1.08};

    TaxableProduct::TaxableProduct (char m_taxes, string m_number, double m_cost){
        m_num = m_number;
        m_Cost = m_cost;
        m_tax = m_taxes;
    }

    double TaxableProduct::getPrice() const {
        if (m_tax == 'H') {
			return m_Cost * rate[tax::HST];
		}
		else if (m_tax == 'P') {
			return m_Cost * rate[tax::PST];
		}
		else {
			return m_Cost * rate[tax::NONE];
		}
    }

    void TaxableProduct::display(std::ostream& os) const {
        if (m_num != "/0") {
			if (m_tax == 'H') {
				os << setw(16) << m_num << setw(16) << m_Cost << setw(4) << "HST";
			}
			if (m_tax == 'P') {
				os << setw(16) << m_num << setw(16) << m_Cost << setw(4) << "PST";
			}
		}
    }
}