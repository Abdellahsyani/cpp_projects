#include "phonebook.hpp"

int	check_strings(std::string words)
{
	if (words.empty())
	{
		std::cout << "Field cannot be empty, try again" << std::endl;
		return 1;
	}
	return 0;
}

void First_name(PhoneBook &phone)
{
	std::string first_name;
	while (true)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, first_name);
		if (!check_strings(first_name))
			break;
	}
	phone.contacts[phone.counter].setfirstname(first_name);
}

void Last_name(PhoneBook &phone)
{
	std::string last_name;
	while (true)
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, last_name);
		if (!check_strings(last_name))
			break;
	}
	phone.contacts[phone.counter].setlastname(last_name);
}


void Nick_name(PhoneBook &phone)
{
	std::string nick_name;
	while (true)
	{
		std::cout << "Enter nick name: ";
		std::getline(std::cin, nick_name);
		if (!check_strings(nick_name))
			break;
	}
	phone.contacts[phone.counter].setnickname(nick_name);
}


int check_phone(std::string phone_number)
{
	for (char c: phone_number)
	{
		if (!std::isdigit(c))
		{
			std::cout << "Just number please" << std::endl;
			return 1;
		}
	}
	return 0;
}

void Phone_number(PhoneBook &phone)
{
	std::string phone_number;
	while (true)
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phone_number);
		if (!check_strings(phone_number) && !check_phone(phone_number))
			break;
	}
	phone.contacts[phone.counter].setphonenumber(phone_number);
}

void Darkest_secret(PhoneBook &phone)
{
	std::string darkest_secret;
	while (true)
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkest_secret);
		if (!check_strings(darkest_secret))
			break;
	}
	phone.contacts[phone.counter].setdarkestsecret(darkest_secret);
}


int	choice_function()
{
	std::string in;

	while (true)
	{
		std::cout << "Do you want to enter more contacts y/n: ";
		std::getline(std::cin, in);
		if (in.empty())
			continue;
		else
			break;
	}
	if (in == "y")
		return 1;
	else if (in == "n")
		return 0;
	return 0;
}

void	start(PhoneBook &phone)
{
	int	i = 0;

	while (i < 2)
	{
		First_name(phone);
		Last_name(phone);
		Nick_name(phone);
		Phone_number(phone);
		Darkest_secret(phone);
		phone.counter++;
		if (!choice_function())
			break;
		i++;
	}
}

int PhoneBook::counter = 0;
PhoneBook::PhoneBook() {};
