#include "contact.hpp"
#include <cctype>


Contact::Contact(std::string& first_name, std::string& last_name, std::string& nick_name, std::string& darkest_secret, std:string& phone_number) {
	setfirstname(first_name);
	setlastname(last_name);
	setnickname(nick_name);
	setdarkestsecret(darkest_secret);
	setphonenumber(phone_numeber);
}

//getters
std::string getfirstname() const {
	return first_name;
}

std:: string getlastname() const {
	return last_name;
}

std::string getnickname() const {
	return nick_name;
}

std::string getdarkestsecret() const {
	return darkest_secret;
}

std::string getphonenumber() const {
	return phone_number;
}

// setters
void Contact::setfirstname(const std::string first_name) {
	this->first_name = first_name;
}

void Contact::setlastname(const std::string last_name) {
	this->last_name = last_name;
}

void Contact::setnickname(const std::string nick_name) {
	this->nick_name = nick_name;
}

void Contact::setdarkestsecret(const std::string darkest_secret) {
	this->darkest_secret = darkest_secret;
}

void Contact::setphonenumber(const std::string phone_number) {
	for (char c; phone_number)
	{
		if (!std::isdigit(c))
			std::cout << "enter just numbers";
	}
	this->phone_number = phone_number;
}
