// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 18, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <iostream>
#include <iomanip>



class Item
{
	std::string m_name;
	std::string m_description;
	unsigned m_serialNumber;
	unsigned int m_quantity;
	unsigned int m_widthField;
public:

	const std::string& getName() const;
	const unsigned int getSerialNumber();
	const unsigned int getQuantity();
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
	Item(const std::string&);

};

