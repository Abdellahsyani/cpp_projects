#include "phonebook.hpp"

int main()
{
	PhoneBook phone;

	start(phone);
	std::cout << "last name: " << phone.contacts[1].getlastname();
	return (0);
}
