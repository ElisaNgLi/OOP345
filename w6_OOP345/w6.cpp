// Workshop 6 - STL Containers
// w6.cpp
// Author: Sean Kevin Surjanto
// ID: 148057177

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"
#include "Product.h"
#include "TaxableProduct.h"
#include <cctype>

std::ostream& w6::operator<<(std::ostream& os, const w6::iProduct& obj) {
	obj.display(os);
	return os;
}

w6::iProduct* readProduct(std::ifstream& file) {
	w6::iProduct* product;
	std::string temp;
	int number;
	double price;
	char tax;
	std::getline(file, temp, '\n');
	try {
		if (temp != "") {
			try {
				if (isdigit(temp[temp.length() - 1])) {
					number = stoi(temp.substr(0, temp.find(" ")));
					price = stod(temp.substr(temp.find(" ")));
					product = new w6::Product(number, price);
				}
				else if (temp[temp.length() - 1] == 'H' || temp[temp.length() - 1] == 'P') {
					if (temp[temp.length() - 1] == 'H') {
						number = stoi(temp.substr(0, temp.find(" ")));
						price = stod(temp.substr(temp.find(" "), temp.find("H") - 1));
						tax = temp[temp.length() - 1];
						product = new w6::TaxableProduct(tax, number, price);
					}
					else {
						number = stoi(temp.substr(0, temp.find(" ")));
						price = stod(temp.substr(temp.find(" "), temp.find("P") - 1));
						tax = temp[temp.length() - 1];
						product = new w6::TaxableProduct(tax, number, price);
					}
				}
				else {
					throw temp;
				}
			}
			catch (std::string err) {
				std::cout << "Line: " << err << " contains invalid tax code" << std::endl;
				product = new w6::Product();
			}
		}
		else {
			throw temp;
		}
	}
	catch (std::string err) {
		std::cout << "Line: " << err << " is empty" << std::endl;
		product = new w6::Product();
	}
	return product;
}

int main(int argc, char** argv) {

	std::ofstream ofs("Lab6Output.txt");

	std::cout << "\nCommand Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2) {
		std::cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}
	std::ifstream productList(argv[1]);
	if (!productList) {
		std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
		return 2;
	}
	ofs << std::fixed << std::setprecision(2);

	//Add your code here

	double total = 0;

	std::vector <const w6::iProduct*> products;
	do {
		products.push_back(readProduct(productList));
	} while (!productList.eof());

	ofs << "Product No" << std::setw(10) << "Price" << std::setw(10) << "Taxable" << std::endl;
	for (size_t i = 0; i < products.size(); i++) {
		ofs << *products[i];
		total += products[i]->getPrice();

	}
	ofs << "Total" << std::setw(15) << total << std::endl;

	std::cout << "Results are in Lab6Output.txt\nPress any key to continue ... ";
	std::cin.get();

	ofs.close();
}

