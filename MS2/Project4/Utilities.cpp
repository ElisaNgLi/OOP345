// Name: Shinchul Jung
// Seneca Student ID: 109311175
// Seneca email: sjung37@myseneca.ca
// Date of completion: 2018-11-18
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

	size_t pos = next_pos + 1;

	next_pos = str.find_first_of(m_delimiter, pos);
	(next_pos == string::npos) ? more = false : more = true;

	string token = str.substr(pos, next_pos - pos);

	if (token.empty()) {
		more = false;
	}

	if (m_widthField < token.length()) {
		m_widthField = token.length();
	}

	return token;
}

void Utilities::setDelimiter(const char setD) {
	m_delimiter = setD;
}

const char Utilities::getDelimiter() const {
	return m_delimiter;
}