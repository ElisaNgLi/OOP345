// Name: Hung Nguyen Trong
// Seneca Student ID:123245177	
// Seneca email: thnguyen35@myseneca.ca
// Date of completion: 20/09/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

using namespace std;
namespace w2
{
    //TO DO:  Default Constructor with one argument
    Text::Text()
    {   
        // Safe empty state
        records = 0;
        file = nullptr;
        delete [] file;
    }

    //TO DO: Text object receives a reference to an unmodifiable string
    Text::Text(const string filesrc)
    {       
        // Connects fin to the file
        ifstream fin(filesrc);
        // Check the condition, if the file cannot open, do safe empty state
        if (!fin.is_open())
        {
            Text();
        }
        else
        {
            size_t line = 0;
            string tempstring;
            while (!fin.eof()) 
            {
                getline(fin, tempstring);
                line++;
            }
            fin.clear();
			fin.seekg(0, ios::beg);
            file = new string[line];
            for (size_t i = 0; i < line + 1; i++) 
            {
                getline(fin, file[i]);
            }
		    records = line;
		    fin.close();
        }
    }

    //TO DO: Copy Constructor
    Text::Text(const Text& filesrc)
    {
        records = filesrc.records;
        if (filesrc.file != nullptr){
            file = new string[records];
             for (size_t i = 0; i < records; i++)
             {
             file[i] = filesrc.file[i];
             }
        }
        else
        {
            file = nullptr;
        }
    }

    //TO DO: Copy Asignment Operator
    Text& Text::operator=(const Text& textsrc)
    {
    if (this != &textsrc)
        {
            delete [] file;
            file = nullptr;
            records = textsrc.records;
            file = new string[records];
            for (size_t i = 0; i < records; i++)
            {
			    file[i] = textsrc.file[i];
            }
        }
        return *this;
    }

    //TO DO: Move Constructor
    Text::Text(Text&& textsrc)
    {
        *this = move(textsrc);
    }

    //TO DO: Move Assignment Operator
    Text& Text::operator=(Text&& textsrc)
    {
        if(this != &textsrc)
        {
            delete[] file;
            file = textsrc.file;
            records = textsrc.records;
            textsrc.file = nullptr;
            textsrc.records = 0;
        }
        return *this;
    }

    //TO DO: Destructor
    Text::~Text()
    {
        delete [] file;
        file = nullptr;
    }

    //TO DO: Member fuction to return the number ò records
    size_t Text::size() const
    {
    return records;
    }
}