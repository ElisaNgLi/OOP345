/**********************************************************
* Name: Elisa Ng
* Student ID: 136265170
* Seneca email: eng-li@myseneca.ca
***********************************************************/
#include "Message.h"

using namespace std;

namespace w4{
	

	Message::Message(ifstream& in, char c){
            string temp;
            getline(in, temp, c);
            if (signed(temp.find_first_of(' ')) != -1)
            {
                m_name.assign(temp.substr(0, (temp.find_first_of(' '))));
                temp.erase(0, (temp.find_first_of(' ')) + 1);
                if (temp.find('@') == 0)
                {
                    m_reply.assign(temp.substr(1, (temp.find_first_of(' ')) - 1));
                    temp.erase(0, (temp.find_first_of(' ')) + 1);
                }
                m_message.assign(temp);
            }
        

        
				
	}

	bool Message::empty() const{
		return m_name.empty() || m_message.empty();
	}

	void Message::display(ostream& os) const{
		if(!empty()){
		os << "Message" << endl;
		os << " User  : " << m_name << endl;
		if(m_reply != "\0"){
			os << " Reply : " << m_reply << endl;
		}

		os << " Tweet : " << m_message << endl;
		os << endl;
	}
	}
}
