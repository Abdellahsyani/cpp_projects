#include "phonebook.hpp"

int main()
{
	PhoneBook phone;
	std::string add;
	std::string search;

	while (true)
	{
		std::cout << "\033[32m" << "Enter Prompt: " << "\033[0m";
		std::getline(std::cin, add);
		if (add.empty())
		{
			std::cout << "\033[31m" << "Empty line: enter(ADD | SEARCH | EXIT)"
				<< "\033[0m" << std::endl;
			continue;
		}
		if (add == "ADD")
			start(phone);
		else if (add == "SEARCH")
			contact_search(phone);
		else if (add == "EXIT")
			exit_phone();
		else
		{
			std::cout << "\033[31m" << "Error: only (ADD | SEARCH | EXIT) allowed"
				<< "\033[0m" << std::endl;
			continue;
		}
	}
	return (0);
}
