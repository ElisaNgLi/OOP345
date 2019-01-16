// Workshop 5 - Containers
// Message.cpp
//Author:  Sean Kevin Surjanto
//Date:    2018-10-04

#include "Message.h"

namespace w4 {

	Message::Message() {
		user = "\0";
		reply = "\0";
		msg = "\0";
	}

	Message::Message(std::ifstream& in, char c) {
		std::string temp;
		std::getline(in, temp, c);

		// if there is no message then put in a safe empty state
		if ((temp.find(" ") + 1) == 0) {
			user = "\0";
			reply = "\0";
			msg = "\0";
		}

		// if there is a message then store accordingly
		else {
			std::string sub;
			user = temp.substr(0, temp.find(" "));
			// if there is no reply
			if ((temp.find("@") + 1) == 0) {
				sub = temp.substr(temp.find(" "));
				reply = "\0";
				msg = sub.substr(1);
			}
			// if there is a reply
			else {
				sub = temp.substr(temp.find("@"));
				reply = sub.substr(1, sub.find(" "));
				msg = sub.substr(sub.find(" ") + 1);
			}
		}
	}

	bool Message::empty() const {
		return (msg == "\0" && user == "\0" && reply == "\0") ? true : false;
	}

	void Message::display(std::ostream& os) const {
		if (!empty()) {
			os << "Message" << std::endl;
			os << " User  : " << user << std::endl;
			if (reply != "\0") {
				os << " Reply : " << reply << std::endl;
			}
			os << " Tweet : " << msg << std::endl;
			os << std::endl;
		}
	}
}