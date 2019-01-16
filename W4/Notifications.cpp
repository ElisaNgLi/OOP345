/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/
#include "Notifications.h"

using namespace std;
namespace w4{

	//Constructor
	Notifications::Notifications(){
		messages.clear();
	}

	//Copy Constructor
	Notifications::Notifications(const Notifications& noti) : Notifications(){
		messages = noti.messages;
	}

	//Copy Assignment Operator
	Notifications& Notifications::operator=(const Notifications& noti) {
		if(this != &noti){
			for(int i = 0; i < 10; ++i){
			messages = noti.messages;
			}
		}
		return *this;
	}

	//Move Constructor
	Notifications::Notifications(Notifications&& noti){
		messages = noti.messages;
		noti.messages.clear();
	}

	//Move Assignment Operator
	Notifications&& Notifications::operator=(Notifications&& noti){
		if(this != &noti){
			for(int i = 0; i < 10; ++i){
				messages = move(noti.messages);
			}
		}
		return move(*this);
	}

	//Destructor
	Notifications::~Notifications(){
		messages.clear();
	}

	void Notifications::operator+=(const Message& mess){
		messages.push_back(mess);
	}

	void Notifications::display(ostream& os) const{
		for(auto mess = messages.begin(); mess != messages.end(); ++mess){
			mess -> display(os);
		}
	}

}
