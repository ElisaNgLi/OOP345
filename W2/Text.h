/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
**********************************************************/
#ifndef W2_TEXT_H
#define W2_TEXT_H

#include <string>
#include <memory>

using namespace std;

namespace w2 {

	class Text {
	
		string* m_String;
		size_t m_Count;

	public:
		Text();
		Text(const string file);
		// Copy constructor
		Text(const Text&);
		// Copy assignment operator
		Text& operator=(const Text&);
		// Move constructor
		Text(Text&&);
		// Move Assignment Operator
		Text& operator=(Text&&);
		// Destructor
		~Text();
		// Returns the number of records of text data
		size_t size() const;
	};
}

#endif
