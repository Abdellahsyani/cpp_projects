#include "phonebook.hpp"

int main()
{
	PhoneBook phone;
	std::string add;
	std::string search;

	while (true)
	{
		std::cout << "what's on your mind(ADD/SEARCH/EXIT): ";
		std::getline(std::cin, add);
		if (add == "ADD")
			start(phone);
		else if (add == "SEARCH")
			contact_search(phone);
		else if (add == "EXIT")
			exit_phone();
	}

	/*std::cout << "first name: " << phone.contacts[0].getfirstname() << std::endl;*/
	/*std::cout << "last name: " << phone.contacts[0].getlastname() << std::endl;*/
	/*std::cout << "nick name: " << phone.contacts[0].getnickname() << std::endl;*/
	/*std::cout << "phone number: " << phone.contacts[0].getphonenumber() << std::endl;*/
	/*std::cout << "darkest secret: " << phone.contacts[0].getdarkestsecret() << std::endl;*/
	return (0);
}
