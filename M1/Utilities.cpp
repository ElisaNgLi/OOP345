// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 18, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

using namespace std;

char Utilities::m_delimiter = ' ';

Utilities::Utilities(){
    m_widthField = 0;
}

void Utilities::setFieldWidth(size_t m_what){
    m_widthField = m_what;
}

size_t Utilities::getFieldWidth() const{
    return m_widthField;
}

const string Utilities::extractToken(const string& str, size_t& next_pos, bool& more){
    size_t m_pos = next_pos + 1;

    next_pos = str.find_first_of(m_delimiter, m_pos);
    if (next_pos == string::npos) {
        more = false;
    }else{
        more = true;
    }

    string token = str.substr(m_pos, next_pos - m_pos);

    if(token.empty()){
        more = false;
    }

    if (m_widthField < token.length()){
        m_widthField = token.length();
    }

    return token;
}

void Utilities::setDelimiter(const char dem){
    m_delimiter = dem;
}

const char Utilities::getDelimiter() const{
    return m_delimiter;
}