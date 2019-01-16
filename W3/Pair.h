/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
**********************************************************/
#ifndef PAIR_H
#define PAIR_H

template <typename A, typename B>
class Pair {
	A m_A;
	B m_B;
public:
	Pair() {};
	Pair(const A& a, const B& b) {
		m_A = a;
		m_B = b;
	};
	const A& getKey() const {
		return m_A;
	};
	const B& getValue() const {
		return m_B;
	};
};

#endif

