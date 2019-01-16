// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 16, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for(size_t i = 0; i < desc.size(); i++)
        {
            for(size_t n = 0; n < price.size(); n++)
            {
                if (desc[i].code == price[n].code)
                {
                    Product* m_ptr = new Product(desc[i].desc, price[n].price);
                    m_ptr->validate();
                    priceList += m_ptr;
                    
                    delete m_ptr;
                    m_ptr = nullptr;
                }
            }
        }

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for(size_t i = 0; i < desc.size(); i++)
        {
            for(size_t n = 0; n < price.size(); n++)
            {
                if (desc[i].code == price[n].code)
                {
                    std::unique_ptr<Product> m_ptr(new Product(desc[i].desc, price[n].price));
                    m_ptr->validate();
                    priceList += m_ptr;
                }
            }
        }

		return priceList;
	}
}