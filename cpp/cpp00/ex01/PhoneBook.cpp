#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"
#include <cstdio> 
#include <string>

std::string to_string(int value) {
    char buffer[20]; 
    sprintf(buffer, "%d", value);
    return std::string(buffer);
}
PhoneBook::PhoneBook(void)
{
    std::cout << "Welcome" << std::endl;
	_nb_contact = 0;
	_oldest_contact = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "See you" << std::endl;
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
void PhoneBook::search()
{
	int i;
	
	i = 0;
    if (_nb_contact == 0)
    {
        std::cout << "No contact registered" << std::endl;
        return;
    }
    std::cout << formatCell("index") << "|"
              << formatCell("first name") << "|"
              << formatCell("last name")  << "|"
              << formatCell("nickname")  << "|" << std::endl;

    while(i < _nb_contact)
    {
        std::cout  << formatCell(to_string(i)) << "|"
                << formatCell(_tab[i].get_fisrt_name()) << "|"
                  << formatCell(_tab[i].get_last_name())  << "|"
                  << formatCell(_tab[i].get_nickname())  << "|" << std::endl;
		i++;
    }

    int index;
    while (1)
    {
        std::cout << "Entrez l'index du contact à afficher : ";
        if (!(std::cin >> index) || index < 0 || index >= _nb_contact)
        {
            std::cout << "Index invalide" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            break;
    }
    std::cout << "First name: "      << _tab[index].get_fisrt_name()    << std::endl;
    std::cout << "Last name: "       << _tab[index].get_last_name()     << std::endl;
    std::cout << "Nickname: "        << _tab[index].get_nickname()      << std::endl;
    std::cout << "Phone: "           << _tab[index].get_phone_number()  << std::endl;
    std::cout << "Darkest secret: "  << _tab[index].get_darkest_secret()<< std::endl;
    std::cout << "Search mode close" << std::endl;
}



std::string PhoneBook::formatCell(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::get_contact(void)
{
	std::cout << _tab[_nb_contact].get_fisrt_name() << std::endl;
}