/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
**********************************************************/

#include <cstring>
#include <iostream>
#include "CString.h"

using namespace std;

int STORED = 3;

namespace w1 {
	//Initialize MAX to the value of STORED
	CString::CString(const char* m) : MAX{ STORED }
	{
		if (m == nullptr) {
			m_string[0] = '\0';
		}
		else {
			strncpy(m_string, m, MAX);
			m_string[MAX + 1] = '\0';
		}
	}

	void CString::display(std::ostream& os) const {
		os << m_string;
	}

	std::ostream& operator<<(std::ostream& os, CString cs) {
		/*static int inc = 0;
		os << inc++ << " : ";*/
		cs.display(os);
		return os;
	}
}
