// Workshop 5 - Containers
// Message.h
//Author:  Sean Kevin Surjanto
//Date:    2018-10-04

#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>
#include <fstream>

namespace w4 {
	class Message {
		std::string user;
		std::string reply;
		std::string msg;
	public:
		Message();
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream&) const;
	};
}
#endif // !MESSAGE_H
