// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 18, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once

#include <deque>
#include <ostream>
#include <string>
#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item {
	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;

public:
	Task(const std::string&);
	Task(Task&) = delete;

	void runProcess(std::ostream&);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&);
	Task& operator+=(CustomerOrder&&);
	Task& operator=(Task&) = delete;

};

