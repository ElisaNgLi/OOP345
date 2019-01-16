// Workshop 8 - Smart Pointers
// Element.h
// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 16, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef W8_ELEMENT_H
#define W8_ELEMENT_H

#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

using namespace std;
namespace w8 {

    struct Description {
        unsigned code;
        std::string desc;
        bool load(std::ifstream& f)
		{
            f >> code >> desc;
            return f.good();
        }

		void display(std::ostream& os) const
		{
            os << std::setw(FWC) << code
			   << std::setw(FWD) << desc
			   << std::endl;
        }
    };

    struct Price {
        unsigned code;
        double price;
        bool load(std::ifstream& f)
		{
            f >> code >> price;
            return f.good();
        }

		void display(std::ostream& os) const
		{
            os << std::setw(FWC) << code << std::setw(FWP)
            << price << std::endl;
        }
    };

    struct Product {
        std::string desc;
        double price;
		int m_id;
		static size_t idGenerator;
		// this variable is used to print trace messages from
		//     constructors/destructor
		static bool Trace;
		Product()
		{
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    DC [" << m_id << "]" << std::endl;
		}
        Product(const std::string& str, double p)
		{
			this->desc = str;
			this->price = p;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "     C [" << m_id << "]" << std::endl;
		}
		Product(const Product& other)
		{
			this->desc = other.desc;
			this->price = other.price;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    CC [" << m_id
			          << "] from [" << other.m_id << "]"
			          << std::endl;
		}
		~Product()
		{
			if (Product::Trace)
				std::cout << "    ~D [" << m_id << "]" << std::endl;
		}



		// TODO: add the validate() function here
		void validate() {
			if (price < 0){
				throw string("*** Negative prices are invalid ***");
			}
		}


        void display(std::ostream& os) const
		{
            os << std::setw(FWD) << desc
			   << std::setw(FWP) << price
			   << std::endl;
        }
    };
}
#endif