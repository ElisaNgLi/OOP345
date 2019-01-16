// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion: Nov 18, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Task.h"

using namespace std;

Task::Task(const string& str) : Item(str) {
	m_pNextTask = nullptr;
}

void Task::runProcess(ostream& os) {
	if (!m_orders.empty()) {
		if (!m_orders.front().getOrderFillState()) {
			while (!m_orders.front().getItemFillState(getName())) {
				if (!getQuantity())
					throw string(" [") + getName() + "] out of stock!***";
				m_orders.front().fillItem(*this, os);
			}
		}
	}
}

bool Task::moveTask() {
	if (!m_orders.empty()) {
		if (m_pNextTask) {
			if (m_orders.front().getItemFillState(getName())) {
				*m_pNextTask += move(m_orders.front());
				m_orders.pop_front();
			}
		}
		return true;
	}
	else {
		return false;
	}
}

void Task::setNextTask(Task& next) {
	m_pNextTask = &next;
}

bool Task::getCompleted(CustomerOrder& order) {
	if (!m_orders.empty() && m_orders.front().getOrderFillState()) {
		order = move(m_orders.front());
		m_orders.pop_front();
		return true;
	}
	else {
		return false;
	}
}

void Task::validate(ostream& os) {
	os << getName() << " --> ";
	os << (m_pNextTask ? m_pNextTask->getName() : "END OF LINE");
	os << endl;
}

Task& Task::operator+=(CustomerOrder&& m_custOrder) {
	m_orders.push_back(move(m_custOrder));
	return *this;
}