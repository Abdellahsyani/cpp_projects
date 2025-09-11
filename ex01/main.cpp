#include "phonebook.hpp"

int main()
{
	PhoneBook phone;

	start(phone);
	std::cout << "last name: " << phone.contacts[0].getfirstname();
	return (0);
}
