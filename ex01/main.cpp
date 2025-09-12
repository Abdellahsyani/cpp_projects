#include "phonebook.hpp"

int main()
{
	PhoneBook phone;

	start(phone);
	std::cout << "first name: " << phone.contacts[0].getfirstname() << std::endl;
	std::cout << "last name: " << phone.contacts[0].getlastname() << std::endl;
	std::cout << "nick name: " << phone.contacts[0].getnickname() << std::endl;
	std::cout << "phone number: " << phone.contacts[0].getphonenumber() << std::endl;
	std::cout << "darkest secret: " << phone.contacts[0].getdarkestsecret() << std::endl;
	return (0);
}
