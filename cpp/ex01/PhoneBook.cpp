#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_nb_contact = 0;
	_oldest_contact = 0;
	std::cout << "constructor" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "destructor" << std::endl;
	return;
}

void PhoneBook::set_contact()
{
	if(_nb_contact < 8)
	{
		_tab[_nb_contact].set_fisrt_name();
		_tab[_nb_contact].set_last_name();
		_tab[_nb_contact].set_nickname();
		_tab[_nb_contact].set_phone_number();
		_tab[_nb_contact].set_darkest_secret();
		std::cout << "Contact add" << std::endl;
		_nb_contact++;
	}
	else
	{
		std::cout << "PhoneBook full the odlest contact has been delete" << std::endl;
		_tab[_oldest_contact].set_fisrt_name();
		_tab[_oldest_contact].set_last_name();
		_tab[_oldest_contact].set_nickname();
		_tab[_oldest_contact].set_phone_number();
		_tab[_oldest_contact].set_darkest_secret();
		_oldest_contact = (_oldest_contact + 1) % 8;
	}
	
}
void	PhoneBook::search()
{
	int i;

	i = 0;
	while(i < _nb_contact)
	{
		std::cout << _tab[i].get_fisrt_name() << '|';
		std::cout << _tab[i].get_last_name() << '|';
		std::cout << _tab[i].get_nickname()  << '|';
		std::cout << _tab[i].get_phone_number()  << '|';
		std::cout << _tab[i].get_darkest_secret() << '|';
		std::cout << std::endl;
		i++;
	}

}

std::string PhoneBook::createPhonebook(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::get_contact(void)
{
	std::cout << _tab[_nb_contact].get_fisrt_name() << std::endl;
}