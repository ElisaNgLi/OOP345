// Name: Shinchul Jung
// Seneca Student ID: 109311175
// Seneca email: sjung37@myseneca.ca
// Date of completion: 2018-11-18
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <string>
#include <iostream>
#include <fstream>


class Utilities {

	size_t m_widthField = '1';
	static char m_delimiter;


public:

	void setFieldWidth(size_t);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char);
	const char getDelimiter() const;
	Utilities();

};