/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
**********************************************************/

#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#include <iostream>

namespace w1 {
	
	class CString {
		const int MAX;
		char m_string[8];
	public:
		CString(const char* m);
		void display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, CString cs);
}

#endif
