/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/
#ifndef SICT_GRADES_H
#define SICT_GRADES_H

#include <iomanip>
#include "Letter.h"

using namespace std;

namespace sict{

    class Grades{

        string* m_Students; //array that holds students
        double* m_Grades;  // array that holds grades
        size_t m_size;    

        public:
        //Contructor
        Grades(const char*);
        //Disable Copy Constructor
        Grades(const Grades&) = delete;
        //Disable Move Constructor
        Grades(Grades&&) = delete;
        //Disable Copy Assign Operator
        Grades& operator=(const Grades&) = delete;
        //Disable Move Assign Operator
        Grades&& operator=(Grades&&) = delete;

        //Template function 
        template<typename F>
        void displayGrades(ostream& os, F lamb) const{
            os << fixed;
            os << setprecision(2);
            for( size_t i = 0; i < m_size; ++i){
                int grades_ = lamb(m_Grades[i]);
                string letter = converter(grades_);

                os << setw(10) << right << m_Students[i] << ' ';
                os << setw(4) << left << m_Grades[i] << ' ';
                os << setw(4) << left << letter << '\n';
            }
        }
    };

     
}

#endif // !SICT_GRADES_H