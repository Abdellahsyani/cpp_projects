#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include "contact.hpp"
#include <limits>

#define BLUE "\033[34m"
#define RESET "\033[0m"

class PhoneBook {
	public:
		static int counter;

		Contact contacts[8];
		PhoneBook();
};

void	start(PhoneBook &phone);
void	contact_search(PhoneBook phone);
void	exit_phone(void);

#endif
