// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 21, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO: rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.

		auto x = bind(converter, text, key, nbytes, Cryptor());
        
        thread t1(x);
        thread t2(x);
        
        t1.join();
        t2.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			ofstream outFile(file, ios::binary | ios::ate);


			// TODO: write data into the binary file
			//         and close the file
			outFile.write(text, nbytes);
            outFile.close();

		}
	}

	void SecureData::restore(const char* file, char key) {
		
		delete[] text;
        nbytes = 0;
		// TODO: open binary file for reading
		
		ifstream inFile(file, ios::binary);

		// TODO: - allocate memory here for the file content
		
        
            inFile >> noskipws;
            
            while (!inFile.eof())
            {
                char m_temp;
                inFile >> m_temp;
                nbytes++;
            }
            
            nbytes--;
            inFile.clear();
            inFile.seekg(0, ios::beg);
            
            text = new char[nbytes + 1];
            
            // TODO: - read the content of the binary file
            inFile.read(text, nbytes);
            text[nbytes] = '\0';

            *ofs << "\n" << nbytes << " bytes copied from binary file " << file << " into memory.\n";
            
            encoded = true;
            
            // decode using key
            code(key);
            
            *ofs << "Data decrypted in memory\n\n";
            inFile.close();
	
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
