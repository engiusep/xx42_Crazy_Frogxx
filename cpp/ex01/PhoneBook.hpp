#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int _nb_contact;
		int _oldest_contact;
		Contact _tab[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	set_contact();
		void	get_contact();
};

#endif