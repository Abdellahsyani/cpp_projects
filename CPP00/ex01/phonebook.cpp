#include "phonebook.hpp"

std::string remove_space(const std::string &s)
{
    size_t start = 0;

    while (start < s.size() && (std::isspace((unsigned char)s[start]) || s[start] == '\t')) {
        start++;
    }

    return s.substr(start);
}

void First_name(PhoneBook &phone)
{
	std::string first_name;
	while (true)
	{
		std::cout << "Enter first name: ";
		read_line(first_name);
		first_name = remove_space(first_name);
		if (!is_valid_input(first_name))
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
		read_line(last_name);
		last_name = remove_space(last_name);
		if (!is_valid_input(last_name))
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
		read_line(nick_name);
		nick_name = remove_space(nick_name);
		if (!is_valid_input(nick_name))
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
			std::cout << "\033[31m" << "Just number please" << "\033[0m" << std::endl;
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
		read_line(phone_number);
		phone_number = remove_space(phone_number);
		if (!is_valid_input(phone_number) && !check_phone(phone_number))
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
		read_line(darkest_secret);
		darkest_secret = remove_space(darkest_secret);
		if (!is_valid_input(darkest_secret))
			break;
	}
	phone.contacts[phone.counter].setdarkestsecret(darkest_secret);
}

void	contact_search(PhoneBook phone)
{
	std::string line  = std::string(51, '-');

	std::cout << BLUE << line << RESET << std::endl;
	std::cout << BLUE << "| " << RESET << std::setw(5) << std::left << "Index"
		<< BLUE <<" | " << RESET << std::setw(12) << "first name"
		<< BLUE << "| " << RESET << std::setw(12) << "last name"
		<< BLUE <<"| " << RESET << std::setw(12) << "nick name"
		<< BLUE << "|" << RESET << std::endl;

	std::cout << BLUE << line << RESET << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (phone.contacts[i].getfirstname().empty())
			continue;
		std::cout << BLUE << "| " << RESET << std::setw(5) << std::left << i
			<< BLUE << " | " << RESET << std::setw(12) << format_column(phone.contacts[i].getfirstname())
			<< BLUE << "| " << RESET << std::setw(12) << format_column(phone.contacts[i].getlastname())
			<< BLUE << "| " << RESET << std::setw(12) << format_column(phone.contacts[i].getnickname())
			<< BLUE << "|" << RESET << std::endl;
	}
	std::cout << BLUE << line << RESET << std::endl;
}

void	start(PhoneBook &phone)
{
	int	i = 0;
	std::string in;

	while (true)
	{
		phone.counter = phone.counter % 8;
		First_name(phone);
		Last_name(phone);
		Nick_name(phone);
		Phone_number(phone);
		Darkest_secret(phone);
		phone.counter++;
		if (!choice_function(in))
			break;
	}
}

int PhoneBook::counter = 0;
PhoneBook::PhoneBook() {};
