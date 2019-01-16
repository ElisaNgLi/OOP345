/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include "Grades.h"


using namespace std;

namespace sict{

    Grades::Grades(const char* file){
        try{
            string line;
            ifstream inFile(file);
            if(inFile.is_open()){
                    while(getline(inFile, line)) {
                        m_size++;
                    }
                    m_Grades = new double[m_size];
                    m_Students = new string[m_size];
                    inFile.clear();
                    inFile.seekg(0, ios::beg);

                    for (size_t i=0; i < m_size; i++){
                        inFile >> m_Students[i];
                        inFile.ignore(1, ' ');
                        inFile >> m_Grades[i];
                        inFile.ignore(1, '\n');
                    }
                    inFile.close();

            } else {
                throw "Unable to open file";
            }
        }
        catch (const char * ex) {
            cout << ex << '\n';
        }

    }
}