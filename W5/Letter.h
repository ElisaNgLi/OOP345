/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/

#ifndef SICT_LETTER_H
#define SICT_LETTER_H

using namespace std;

namespace sict{

    enum Letter {Ap, A, Bp, B, Cp, C, Dp, D, F};
    template <typename T>
        const char* converter(const T& letter){

            switch(letter){
                case Ap:
                    return "A+";
                case A:
                   return "A";
                case Bp:
                    return "B+";
                case B:
                    return "B";
                case Cp:
                return "C+";
                case C:
                    return "C";
                case Dp:
                    return "D+";
                case D:
                    return "D";
                default:
                    return "F";
            }
       }
}

#endif // !SICT_LETTER_H