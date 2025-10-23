#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>



int	main()
{
	PhoneBook phonebook;
	std::string buffer;

	while(1)
	{
		std::cout << "Usage SEARCH, ADD, EXIT : ";
		if(!std::getline(std::cin,buffer))
		{
			break;
		}
		if(buffer == "ADD")
		{
			phonebook.set_contact();
		}
		if(buffer == "EXIT")
			exit(EXIT_FAILURE);
		if(buffer == "SEARCH")
		{
			phonebook.search();
		}
		  std::cin.clear();
	}
	return (0);
}