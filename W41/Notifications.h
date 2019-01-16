// Workshop 5 - Containers
// Notifications.h
//Author:  Sean Kevin Surjanto
//Date:    2018-10-04

#ifndef NOTIFICATION_H
#define NOTIFICATION_H 
#include <iostream>
#include "Message.h"

namespace w4{
	class Notifications {
		Message messageArray[10];
		size_t x = 0;
	public:
		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		~Notifications();
		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
	};
}

#endif
