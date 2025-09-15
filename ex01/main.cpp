#include "phonebook.hpp"

int main()
{
	PhoneBook phone;
	std::string add;
	std::string search;

	while (true)
	{
		std::cout << "\033[32m" << "Enter Prompt: " << "\033[0m";
		if (!std::getline(std::cin, add))
    		{
        		if (std::cin.eof())
        		{
           			std::cout << "\n\033[31mEOF detected, exiting...\033[0m" << std::endl;
				std::exit(0);
        		}
		}
		if (add == "ADD")
			start(phone);
		else if (add == "SEARCH")
			contact_search(phone);
		else if (add == "EXIT")
			exit_phone();
		else
		{
			std::cout << "\033[31m" << "Error: only (ADD | SEARCH | EXIT) allowed" << "\033[0m" << std::endl;
			continue;
		}
	}

	return (0);
}
