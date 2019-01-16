// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion:Nov 18, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

using namespace std;

class Utilities {
    
    size_t m_widthField = '1';
    static char m_delimiter;

    public:
    Utilities();
    void setFieldWidth(size_t);
    size_t getFieldWidth() const;
    const string extractToken(const string& str, size_t& next_pos, bool& more);
    static void setDelimiter(const char);
    const char getDelimiter() const;
};

#endif