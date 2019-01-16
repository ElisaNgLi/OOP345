// Name: Hwisun Bae
// Seneca Student ID: 128-835-170
// Seneca email: hbae22@myseneca.ca
// Date of completion: 2018-11-17
#include "Utilities.h"

char Utilities::m_delimiter = ',';

Utilities::Utilities() : m_widthField(0){

}
void Utilities::setFieldWidth(size_t width) {
    m_widthField = width;
}
size_t Utilities::getfieldWidth() const{
    return m_widthField;
}
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
    
    size_t pos = next_pos + 1;
    
    next_pos = str.find_first_of(m_delimiter, pos);
    if(next_pos == std::string::npos){
        more = false;
    } else more = true;
    
    std::string token = str.substr(pos, next_pos - pos );
    
    if (token.empty()) {
        more = false;
    }
    
    if (m_widthField < token.length()) {
        m_widthField = token.length();
    }
    
    return token;
}
void Utilities::setDelimiter(const char d){
    m_delimiter = d;
}
const char Utilities::getDelimiter() const{
    return m_delimiter;
}
