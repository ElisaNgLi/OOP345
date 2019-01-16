// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 18, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include <iostream>
#include <string>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include "Utilities.h"


using namespace std;

char Utilities::m_delimiter = ' ';

Utilities::Utilities() {
	m_widthField = 0;
}

void Utilities::setFieldWidth(size_t setF) {
	m_widthField = setF;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

const string Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {
	   	 
	size_t pos = next_pos;
	size_t end = str.find(m_delimiter, pos);

	string substr;

	if (end == string::npos) {
		more = false;
		substr = str.substr(pos);
		if (substr.back() == '\n' || substr.back() == '\r')
			substr.pop_back();
	}
	else {
		more = true;
		next_pos = end + 1u;
		
		substr = str.substr(pos, end - pos);
	}

	if (substr.size() > m_widthField)
		m_widthField = substr.size();

	return substr;
}

void Utilities::setDelimiter(const char setD) {
	m_delimiter = setD;
}

const char Utilities::getDelimiter() const {
	return m_delimiter;
}