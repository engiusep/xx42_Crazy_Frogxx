#include <iostream>
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
	
	_tab[_nb_contact].set_fisrt_name();
	_tab[_nb_contact].set_last_name();
	_tab[_nb_contact].set_nickname();
	_tab[_nb_contact].set_phone_number();
	_tab[_nb_contact].set_darkest_secret();
	std::cout << "Contact add" << std::endl;
	_nb_contact++;
}

void PhoneBook::get_contact(void)
{
	std::cout << _tab[_nb_contact].get_fisrt_name() << std::endl;
}