#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>



int	main(int argc,char **argv)
{
	int i;
	i = 0;
	PhoneBook repertoire;
	std::string buffer;

	while(1)
	{
		std::getline(std::cin,buffer);

		if(buffer == "ADD")
		{
			repertoire.set_contact();
		}
		if(buffer == "EXIT")
			exit(1);
		if(buffer == "SEARCH")
		{

		}

	}

	std::cout << buffer << std::endl;
	return (0);
}