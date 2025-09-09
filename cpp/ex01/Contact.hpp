#include <iostream>
#include "PhoneBook.hpp"
#ifndef Contact_H
#define Contact_H


class Contact
{
	private:
		std::string _fisrt_name;
		std::string _last_name;
		std::string _nickname;
		std::string	_phone_number;
		std::string _darkest_secret;
	public:
		Contact(void);
		~Contact(void);
		std::string get_fisrt_name();
		void set_fisrt_name();
		void set_last_name();
		void set_nickname();
		void set_phone_number();
		void set_darkest_secret();
};

#endif
