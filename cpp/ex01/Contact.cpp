#include "Contact.hpp"
#include <string>

Contact::Contact(void)
{
	return;
}
Contact::~Contact(void)
{
	return;
}

void Contact::set_fisrt_name()
{
	std::string str;
	std::cout << "set fisrt name" << std::endl;
	std::getline(std::cin,str);
	_fisrt_name = str;
}
void Contact::set_last_name()
{
	std::string str;
	std::cout << "set last name" << std::endl;
	std::getline(std::cin,str);
	_last_name = str;
}
void Contact::set_nickname()
{
	std::string str;
	std::cout << "set nickname" << std::endl;
	std::getline(std::cin,str);
	_nickname = str;
}
void Contact::set_phone_number()
{
	std::string str;
	std::cout << "set phone number" << std::endl;
	std::getline(std::cin,str);
	_phone_number = str;
}
void Contact::set_darkest_secret()
{
	std::string str;
	std::cout << "set darkest secret" << std::endl;
	std::getline(std::cin,str);
	_darkest_secret = str;
}

std::string	Contact::get_fisrt_name()
{
	return (this->_fisrt_name);
}
std::string	Contact::get_last_name()
{
	return (this->_last_name);
}
std::string	Contact::get_nickname()
{
	return (this->_nickname);
}
std::string	Contact::get_phone_number()
{
	return (this->_phone_number);
}
std::string	Contact::get_darkest_secret()
{
	return (this->_darkest_secret);
}

