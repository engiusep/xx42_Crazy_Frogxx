#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>



int	main()
{
	int i;
	i = 0;
	PhoneBook phonebook;
	std::string buffer;

	while(1)
	{
		std::cout << "Usage SEARCH, ADD, EXIT : ";
		std::getline(std::cin,buffer);
		if(buffer == "ADD")
		{
			phonebook.set_contact();
		}
		if(buffer == "EXIT")
			return (0);
		if(buffer == "SEARCH")
		{
			phonebook.search();
		}

	}

	std::cout << buffer << std::endl;
	return (0);
}