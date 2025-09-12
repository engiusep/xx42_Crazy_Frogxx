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
	while(1)
	{
		bool valid = true;
		std::getline(std::cin,str);
		if(str.empty())
		{
			valid = false;
			std::cout << "empty string Put string valid for u fisrt name : " << std::endl;
		}
		if(valid)
		{
			_fisrt_name = str;
			return;
		}
	}
	
}
void Contact::set_last_name()
{
	std::string str;
	std::cout << "set last name" << std::endl;

	while(1)
	{
		bool valid = true;
		std::getline(std::cin,str);
		if(str.empty())
		{
			valid = false;
			std::cout << "empty string Put string valid for u last name : " << std::endl;
		}
		if(valid)
		{
			_last_name = str;
			return;
		}
	}
}
void Contact::set_nickname()
{
	std::string str;
	std::cout << "set nickname" << std::endl;
	while(1)
	{
		bool valid = true;
		std::getline(std::cin,str);
		if(str.empty())
		{
			valid = false;
			std::cout << "empty string Put string valid for u nickname : " << std::endl;
		}
		if(valid)
		{
			_nickname = str;
			return;
		}
	}
}
void Contact::set_phone_number()
{
	std::string str;
	
	std::cout << "set phone number" << std::endl;
	int i;
	while(1)
	{
		i = 0;
		bool valid = true;
		std::getline(std::cin,str);
		while(str[i])
		{
			if(!isdigit(str[i]))
			{
				valid = false;
				break;
			}
			i++;
		}
		if(valid && !str.empty() && str.length() == 10)
		{
			_phone_number = str;
			break;
		}
		else
		{
			std::cout << "Invalid number put only digit and 10 digit is mandatory" << std::endl;
		}
	}
}
void Contact::set_darkest_secret()
{
	std::string str;
	std::cout << "set darkest secret" << std::endl;
	while(1)
	{
		bool valid = true;
		std::getline(std::cin,str);
		if(str.empty())
		{
			valid = false;
			std::cout << "empty string Put string valid for u darkest secret : " << std::endl;
		}
		if(valid)
		{
			_darkest_secret = str;
			return;
		}
	}
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

