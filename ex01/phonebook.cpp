#include "phonebook.hpp"

std::string format_column(const std::string &s)
{
    if (s.length() > 10)
        return s.substr(0, 9) + ".";
    return s;
}

int is_valid_input(const std::string &s)
{
	if (s.empty())
	{
		std::cout << "\033[31m" <<"Field cannot be empty, try again" << "\033[0m" << std::endl;
		return 1;
	}

	for (char c : s)
	{
		if (c < 32 || c == 127)
		{
			std::cout << "\033[31m" <<"Invalid characters, try again" << "\033[0m" << std::endl;
			return 1;
		}
	}
	return 0;
}

void	read_line(std::string &str)
{
	if (!std::getline(std::cin, str))
	{
		if (std::cin.eof())
		{
			std::cout << "\n\033[31mEOF detected, exiting...\033[0m" << std::endl;
			std::exit(0);
		}
	}
}

void First_name(PhoneBook &phone)
{
	std::string first_name;
	while (true)
	{
		std::cout << "Enter first name: ";
		read_line(first_name);
		if (!is_valid_input(first_name))
			break;
	}
	if (phone.flag == 1)
	{
		phone.contacts[phone.counter_2].setfirstname(first_name);
		phone.flag = 0;
	}
	else
		phone.contacts[phone.counter].setfirstname(first_name);
}

void Last_name(PhoneBook &phone)
{
	std::string last_name;
	while (true)
	{
		std::cout << "Enter last name: ";
		read_line(last_name);
		if (!is_valid_input(last_name))
			break;
	}
	if (phone.flag == 1)
	{
		phone.contacts[phone.counter_2].setfirstname(last_name);
		phone.flag = 0;
	}
	else
		phone.contacts[phone.counter].setlastname(last_name);
}


void Nick_name(PhoneBook &phone)
{
	std::string nick_name;
	while (true)
	{
		std::cout << "Enter nick name: ";
		read_line(nick_name);
		if (!is_valid_input(nick_name))
			break;
	}
	if (phone.flag == 1)
	{
		phone.contacts[phone.counter_2].setfirstname(nick_name);
		phone.flag = 0;
	}
	else
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
		if (!is_valid_input(phone_number) && !check_phone(phone_number))
			break;
	}
	if (phone.flag == 1)
	{
		phone.contacts[phone.counter_2].setfirstname(phone_number);
		phone.flag = 0;
	}
	else
		phone.contacts[phone.counter].setphonenumber(phone_number);
}

void Darkest_secret(PhoneBook &phone)
{
	std::string darkest_secret;
	while (true)
	{
		std::cout << "Enter darkest secret: ";
		read_line(darkest_secret);
		if (!is_valid_input(darkest_secret))
			break;
	}
	if (phone.flag == 1)
	{
		phone.contacts[phone.counter_2].setfirstname(darkest_secret);
		phone.flag = 0;
	}
	else
		phone.contacts[phone.counter].setdarkestsecret(darkest_secret);
}

int	choice_function(std::string& in)
{

	while (true)
	{
		std::cout << "Do you want to enter more contacts y/n: ";
		if (!std::getline(std::cin, in))
		{
			if (std::cin.eof())
			{
				std::cout << "\n\033[31mEOF detected, exiting...\033[0m" << std::endl;
				std::exit(0); 
			}
		}
		if (in.empty())
			continue;
		else if (in != "y" && in != "n")
			continue;
		else
			break;
	}
	if (in == "y")
		return 1;
	else if (in == "n")
		return 0;
	return -1;
}

void exit_phone(void)
{
	std::cout << "\033[32m" << R"(
  	 ____                 _ _                
  	/ ___| ___   ___   __| | |__  _   _  ___ 
 	| |  _ / _ \ / _ \ / _` | '_ \| | | |/ _ \
	 | |_| | (_) | (_) | (_| | |_) | |_| |  __/
  	\____|\___/ \___/ \__,_|_.__/ \__, |\___|
                                 |___/     
	)" << "\033[0m" << std::endl;
	std::exit(0);
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
		First_name(phone);
		Last_name(phone);
		Nick_name(phone);
		Phone_number(phone);
		Darkest_secret(phone);
		std::cout << "Index that filled: " << phone.counter << std::endl;
		phone.counter++;
		if (!choice_function(in))
			break;
		if (phone.counter == 7 && in == "y")
		{
			phone.flag = 1;
			/*phone.counter = 0;*/
		}
		if (phone.counter_2 == 7 && in == "y")
		{
			phone.flag = 1;
			/*phone.counter_2 = 0;*/
		}
	}
}

int PhoneBook::counter = 0;
int PhoneBook::counter_2 = 0;
PhoneBook::PhoneBook() {};
