// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion:Nov 30, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Task.h"

using namespace std;

Task::Task(string& record) : Item(record){
    m_pNextTask = nullptr;
}

void Task::runProcess(ostream& os){
    if (!m_orders.empty()){
        if (!m_orders.front().getOrderFillState()){
            while (!m_orders.front().getItemFillState(getName())){
                m_orders.front().fillItem(*this, os);
            }
        }
    }

}

bool Task::moveTask(){
    if (!m_orders.empty()){
        if (m_pNextTask){
            if (m_orders.front().getItemFillState(getName())){
                *m_pNextTask += move(m_orders.front());
                m_orders.pop_front();
            }
        }
        return true;
    }else{
        return false;
    }
}

void Task::setNextTask(Task& what){
    m_pNextTask = &what;
}

bool Task::getCompleted(CustomerOrder& m_cntOrder){
    if(!m_orders.empty() && m_orders.front().getOrderFillState()){
        m_cntOrder = move(m_orders.front());
        m_orders.pop_front();
        return true;
    }else{
        return false;
    }
}

void Task::validate(ostream& os){
    os << getName() << " --> ";
    os << (m_pNextTask ? m_pNextTask->getName() : "END OF LINE") << endl;
}

Task& Task::operator+=(CustomerOrder&& m_cntOrder){
    m_orders.push_back(move(m_cntOrder));
    return *this;
}