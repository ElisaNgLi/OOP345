// Name: Hwisun Bae
// Seneca Student ID: 128-835-170
// Seneca email: hbae22@myseneca.ca
// Date of completion: 2018-11-17
#pragma once

#include <iostream>
#include <string>
using namespace std;

class Utilities {
    size_t m_widthField {0};
    static char m_delimiter;
public:
    Utilities();
    void setFieldWidth(size_t);
    size_t getfieldWidth() const;
    const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(const char);
    const char getDelimiter() const;
};
