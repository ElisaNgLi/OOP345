// Name: Elisa Ng
// Seneca Student ID: 136265180
// Seneca email: eng-li@myseneca.ca
// Date of completion:Nov 30, 2018
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"
#include "Task.h"
#include "Utilities.h"

using namespace std;

LineManager::LineManager(const string& record, vector<Task*>& what, vector<CustomerOrder>& m_cntOrder){
    ifstream file(record);
    
    if (!file){
	    throw string("Unable to open [") + record + "] file.";
    }

    Utilities m_util;
    size_t next_pos = 0;
    bool more = true;

    string str;
    string task;
    string next;

    bool First = true;

    while(!file.eof()) {
        getline(file, str);

        if (str.empty()){
            throw string("*** Empty Record in [") + record + "] ***";
        }

        task = m_util.extractToken(str, next_pos, more);
        if (more){
            next = m_util.extractToken(str, next_pos, more);
        }

        for (size_t i = 0; i < what.size(); ++i) {
            if (what[i]->getName() == task) {
                // This is to save the position of the first task
                if (First) {
                    m_first = i;
                    First = !First;
                }
                
                if (!next.empty()) {
                    for (size_t j = 0; j < what.size(); ++j) {
                        if (what[j]->getName() == next) {
                            what[i]->setNextTask(*what[j]);
                            break;
                        }
                    }
                } else {
                    m_last = i;
                }
                break;
            }
        }
        // This is to reset
        next_pos = 0;
        more = true;
        task.clear();
        next.clear();
    }

    for (size_t i = 0; i < m_cntOrder.size(); ++i) {
        ToBeFilled.push_back(move(m_cntOrder[i]));
    }
    m_cntOrder.erase(m_cntOrder.begin(),m_cntOrder.end());

    AssemblyLine = what;

}

bool LineManager::run(ostream& os){
    if(!ToBeFilled.empty()){
        *AssemblyLine[m_first] += move(ToBeFilled.front());
        ToBeFilled.pop_front();
    }

    for (size_t i = 0; i < AssemblyLine.size(); ++i){
        AssemblyLine[i] -> runProcess(os);
       
    }

    CustomerOrder rem;
    if(AssemblyLine[m_last] -> getCompleted(rem)){
        Completed.push_back(move(rem));
    }

    for (size_t i =0; i < AssemblyLine.size(); ++i){
        if (AssemblyLine[i] -> moveTask()){
            return false;
        }
    }

    return true;

}

void LineManager::displayCompleted(ostream& os) const{
    if (!Completed.empty()){
        for (size_t i = 0; i < Completed.size(); ++i){
            Completed[i].display(os);
        }
    }
}

void LineManager::validateTasks() const{
    if (!AssemblyLine.empty()){
        for (size_t i = 0; i <AssemblyLine.size(); ++i){
            AssemblyLine[i] -> validate(cout);
        }
    }
}

