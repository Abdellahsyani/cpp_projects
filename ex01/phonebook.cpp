#include "phonebook.hpp"



void	start(PhoneBook &phone)
{
	int	i = 0;
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

	while (i < 8)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, first_name);
		std::cout << "Enter last name: ";
		std::getline(std::cin, last_name);
		std::cout << "Enter nick name: ";
		std::getline(std::cin, nick_name);
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phone_number);
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkest_secret);

		phone.contacts[i].setfirstname(first_name);
		phone.contacts[i].setlastname(last_name);
		phone.contacts[i].setnickname(nick_name);
		phone.contacts[i].setphonenumber(phone_number);
		phone.contacts[i].setdarkestsecret(darkest_secret);
		i++;
	}
}

int PhoneBook::counter = 0;

PhoneBook::PhoneBook() {};
