// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion:Nov 30, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <vector>
#include <deque>
#include <iostream>
#include <fstream>
#include "CustomerOrder.h"
#include "Task.h"


using namespace std;

class LineManager{
    vector<Task*>AssemblyLine;
    deque<CustomerOrder> ToBeFilled;
    deque<CustomerOrder>Completed;
    unsigned int m_cntCustomerOrder;
    size_t m_first;
    size_t m_last;

    public:
    LineManager(const string&, vector<Task*>&, vector<CustomerOrder>&);
    bool run(ostream&);
    void displayCompleted(ostream& ) const;
    void validateTasks() const;
};

#endif