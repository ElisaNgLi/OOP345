// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 18, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <list>
#include <iostream>
#include <fstream>
#include "Task.h"
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

LineManager::LineManager(const string& str, vector<Task*>& tasks, vector<CustomerOrder>& orders) {
	ifstream file(str);

	if (!file)
		throw string("Unable to open [") + str + "] file.";

	Utilities m_util;
	size_t next_pos = 0;
	bool more = true;

	string record;
	string task;
	string next;

	bool first = true;

	
	while (!file.eof()) {
		getline(file, record);

		if (record.empty())
			throw string("No data in [") + str + "] ***";

		task = m_util.extractToken(record, next_pos, more);
		if (more)
			next = m_util.extractToken(record, next_pos, more);

		for (size_t i = 0; i < tasks.size(); ++i) {
			if (tasks[i]->getName() == task) {
				// save position of first task
				if (first) {
					m_firstTask = i;
					first = !first;
				}

				if (!next.empty()) {
					for (size_t j = 0; j < tasks.size(); ++j) {
						if (tasks[j]->getName() == next) {
							tasks[i]->setNextTask(*tasks[j]);
							break;
						}
					}
				}
				else {
					m_lastTask = i;
				}

				break;
			}
		}

		// reset
		next_pos = 0;
		more = true;
		task.clear();
		next.clear();
	}

	for (size_t i = 0; i < orders.size(); ++i)
		ToBeFilled.push_back(move(orders[i]));
	orders.erase(orders.begin(), orders.end());

	AssemblyLine = tasks;
}

bool LineManager::run(ostream& os) {
	bool finish = true;

	if (!ToBeFilled.empty()) {
		*AssemblyLine[m_firstTask] += move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (size_t i = 0; i < AssemblyLine.size(); ++i) {
		
		AssemblyLine[i]->runProcess(os);
	
	}

	CustomerOrder m_buffer; 
	if (AssemblyLine[m_lastTask]->getCompleted(m_buffer))
		Completed.push_back(move(m_buffer));

	
	for (size_t i = 0; i < AssemblyLine.size(); ++i) {
		
		if (AssemblyLine[i]->moveTask()) {
			finish = false;

		}
	}

	return finish;
}

void LineManager::displayCompleted(ostream& os) const {
	if (!Completed.empty())
		for (size_t i = 0; i < Completed.size(); ++i)
			Completed[i].display(os);
}

void LineManager::validateTasks() const {
	if (!AssemblyLine.empty())
		for (size_t i = 0; i < AssemblyLine.size(); ++i)
			AssemblyLine[i]->validate(cout);
}