/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/
#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
namespace w4{

	class Message{

		string m_name;
		string m_reply;
		string m_message;

		public:
			
			Message(std::ifstream& in, char c);
			bool empty() const;
			void display(std::ostream&) const;
	};
	
}

#endif
