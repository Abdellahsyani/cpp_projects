#include "contact.hpp"
#include <cctype>

Contact::Contact() {
      first_name = "";
      last_name = "";
      nick_name = "";
      phone_number = "";
      darkest_secret = "";
}


//getters
std::string Contact::getfirstname() const {
	return first_name;
}

std:: string Contact::getlastname() const {
	return last_name;
}

std::string Contact::getnickname() const {
	return nick_name;
}

std::string Contact::getdarkestsecret() const {
	return darkest_secret;
}

std::string Contact::getphonenumber() const {
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
	this->phone_number = phone_number;
}

