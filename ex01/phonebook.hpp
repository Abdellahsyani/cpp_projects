#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "contact.hpp"

class PhoneBook {
	public:
		static int counter;

		Contact contacts[8];
		PhoneBook();

		//display methods 
		void	add_contact(Contact contact);
		std::string	search_contact(int id);
		void	exit_contact();
};

void	start(PhoneBook &phone);

#endif
