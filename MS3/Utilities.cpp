// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 18, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

using namespace std;

char Utilities::m_delimiter;

void Utilities::setFieldWidth(size_t m_what){
    m_widthField = m_what;
}

size_t Utilities::getFieldWidth() const{
    return m_widthField;
}

const string Utilities::extractToken(const string& str, size_t& next_pos, bool& more){

    // if (!more){
    //  throw "*** Nothing to extract!! ***";
    // }

    // // check for the last character
    // if (next_pos + 1u >= str.size()) {
    //     throw int(-1);
    // }

    // size_t cur_pos = next_pos;
    // // search for next delimiter
    // size_t end_pos = str.find(m_delimiter, cur_pos);

    // string substr;
    
    // // check if final delimiter
    // if (end_pos == string::npos) {
    //     more = false;
    //     substr = str.substr(cur_pos);
    //     // pop_back any "next line" characters
    //     if (substr.back() == '\n' || substr.back() == '\r')
    //         substr.pop_back();
    // } else {
    //     more = true;
    //     next_pos = end_pos + 1u;
    //     if (end_pos == cur_pos)        
    //         throw "*** Nothing between delimiters ***";
    //     substr = str.substr(cur_pos, end_pos-cur_pos);
    // }

    // if (substr.size() > m_widthField) 
    //     m_widthField = substr.size();

    // return substr;

    size_t pos = next_pos;
	size_t end = str.find(m_delimiter, pos);

	std::string substr;

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

void Utilities::setDelimiter(const char dem){
    m_delimiter = dem;
}

const char Utilities::getDelimiter() const{
    return m_delimiter;
}