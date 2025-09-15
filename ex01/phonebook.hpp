#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include "contact.hpp"
#include <limits>
#include <fstream>

#define BLUE "\033[34m"
#define RESET "\033[0m"

class PhoneBook {
	public:
		static int counter;
		int	flag = 0;
		int static counter_2;

		Contact contacts[8];
		PhoneBook();
};

void	start(PhoneBook &phone);
void	contact_search(PhoneBook phone);
void	exit_phone(void);
int	is_valid_input(const std::string &s);
std::string	format_column(const std::string &s);
int	choice_function(std::string& in);
void	read_line(std::string &str);

#endif
