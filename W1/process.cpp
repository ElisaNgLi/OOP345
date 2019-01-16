/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
**********************************************************/

#include <iostream>
#include "process.h"
#include "CString.h"

using namespace std;
using namespace w1;

	void process(const char* m, std::ostream& os) {
		static int inc = 0;
		w1::CString str(m);
		os << inc++ << " : " << str << endl;
	}

