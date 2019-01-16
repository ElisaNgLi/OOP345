// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion:Nov 30, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef TASK_H
#define TASK_H

#include <deque>
#include <ostream>
#include <string>

#include "Item.h"
#include "CustomerOrder.h"

using namespace std;

class Task : public Item {

    deque<CustomerOrder> m_orders;
    Task* m_pNextTask;

    public:
    Task(string&);
    //Copy constructor
    Task(Task&) = delete;
    //Move Constructor
    Task(Task&&) = delete;
    //Copy Operator
    Task& operator =(Task&) = delete;
    //Move Operator
    Task& operator=(Task&&) = delete;
    void runProcess(ostream& );
    bool moveTask();
    void setNextTask(Task&);
    bool getCompleted(CustomerOrder&);
    void validate(ostream&);
    Task& operator+=(CustomerOrder&&);
};

#endif