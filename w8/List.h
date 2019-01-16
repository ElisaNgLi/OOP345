 // Workshop 8 - Smart Pointers
 // List.h
 // Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 16, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef W8_LIST_H
#define W8_LIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

using namespace std;

namespace w8 {
    template <typename T>
    class List {
		std::vector<T> list;
	public:
		List() { }
		List(const char* fn) {
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
            while (file) {
                T e;
                if (e.load(file))
                    list.push_back(*new T(e));
            }
		}
		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		// TODO: Overload the += operator with a smart pointer
		//       as a second operand.
		void operator+=(const unique_ptr<T>& m_ptr){
			list.push_back(*m_ptr);
		}


		// TODO: Overload the += operator with a raw pointer
		//       as a second operand.
		void operator+=(const T* m_ptr){
			list.push_back(*m_ptr);
		}


		void display(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.display(os);
        }
	};

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const List<T>& l) {
		l.display(os);
		return os;
	}
}
#endif