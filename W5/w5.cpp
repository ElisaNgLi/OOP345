// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include "Grades.h"
#include "Letter.h"

using namespace std;
using namespace sict;

int main(int argc, char* argv[]) {

    std::cout << "Command Line: ";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << ' ';
    std::cout << std::endl;

    if (argc == 1) {
        std::cerr << "\n*** Insufficient number of arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 1;
    }
    else if (argc != 2) {
        std::cerr << "\n*** Too many arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 2;
    }
    try {
		Grades grades(argv[1]);

		// Lambda expression for converting to letter 
		auto letter = [](double grade) 
		{
			int gd;
			if ((grade >= 90) && (grade <= 100)) { gd = Ap; }
			else if ((grade >= 80) && (grade < 90)) { gd = A; }
			else if ((grade >= 75) && (grade < 80)) { gd = Bp; }
			else if ((grade >= 70) && (grade < 75)) { gd = B; }
			else if ((grade >= 65) && (grade < 70)) { gd = Cp; }
			else if ((grade >= 60) && (grade < 65)) { gd = C; }
			else if ((grade >= 55) && (grade < 60)) { gd = Dp; }
			else if ((grade >= 50) && (grade < 55)) { gd = D; }
			else { gd = F; }

			return gd;
		};

        //TODO: Update the main functions as per the specifications here
        grades.displayGrades(std::cout, letter);
    }

    catch (const char *mess) {
		// report the error message
		cerr << argv[0] << mess << argv[1] << "\n";
	}

    return 0;
}