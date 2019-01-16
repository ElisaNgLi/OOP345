/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
**********************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "Text.h"

using namespace std;

namespace w2 {
	
	Text::Text(){
		m_Count = 0;
		m_String = nullptr;
		//delete [] m_String;
	}

	Text::Text(const string file){
		// Connects m_file to the file
		ifstream m_file( file);
		// Check condition for the file, if this open read the lines 
		//and count it otherwise do safe empty state
		if(m_file.is_open()){
			size_t count = 0;
			string str;
			while(!m_file.eof()){
				getline(m_file,str);
				count++;
			}
			m_file.clear();
			m_file.seekg(0, ios::beg);
			m_String = new string[count];

			for (size_t i = 0; i < count; ++i){
				getline(m_file, m_String[i]);
			}
			m_Count = count;
			m_file.close();
		}else{
			Text();
		}
	}


	//Copy Constructor
	Text::Text(const Text& oth) {
		*this = oth;
	}

	// Copy assignment operator
	Text& Text::operator=(const Text& old) {
		if (this != &old) {

			delete[] m_String;
			m_String = nullptr;
			m_Count = old.m_Count;
			m_String = new string[m_Count];

			for (size_t i = 0; i < m_Count; ++i) {

				m_String[i] = old.m_String[i];
			}
		}
		return *this;
	}
	// Move constructor
	Text::Text(Text&& m) {
		*this = move(m);
		/*m_Name = m.m_Name;

		m_String = m.m_String;
		m_Count = m.m_Count;

		for (size_t i = 0; i < m_Count; ++i){
			m_String[i] = m.m_String[i];
		}

		m.m_String = nullptr;

		delete [] m_String;
		m_String = nullptr;
		m_Name = "";
		m_Count = 0;*/
	}

	// Move Assignment Operator
	Text& Text::operator=(Text&& m) {
		if (this != &m) {

			m_Count = m.m_Count;
			delete [] m_String;
			m_String = m.m_String;
			m.m_String = nullptr;
			m.m_Count = 0;

		}
		return *this;
	}
	// Destructor
	Text::~Text() {
		delete[] m_String;
		m_String = nullptr;
	}
	// Returns the number of records of text data
	size_t Text::size() const {
		return m_Count;
	}
}
