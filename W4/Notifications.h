/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/
#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H

#include <iostream>
#include <vector>
#include "Message.h"

namespace w4{

	class Notifications{

		std::vector<Message> messages;
		//Message m_arraymess[10];
		//size_t num = 0;	
		public:
			//Constructor
			Notifications();
			//Copy Constructor
			Notifications(const Notifications&);
			//Copy Assignment Operator
			Notifications& operator=(const Notifications&);
			//Move Constructor
			Notifications(Notifications&&);
			//Move Assignment Operator
			Notifications&& operator=(Notifications&&);
			//Destructor
			~Notifications();
			void operator+=(const Message& msg);
			void display(std::ostream& os) const;
	};
}

#endif
