/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
**********************************************************/
#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

template <typename T, int N>
class List {

	T m_Size[N];
	size_t m_Count;
	T M_No;

public:
	List() {
		m_Count = 0;
	};
	size_t size() const {
		return m_Count;
	};
	const T& operator[] (int index) const {
		if (index >= 0 && index < m_Count) {
			return m_Size[index];
		}
		else {
			return M_No;
		}
	};
	void operator+=(const T& m) {
		if (m_Count < N) {
			m_Size[m_Count] = m;
			m_Count++;
		}
	};
};
#endif

