#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string darkest_secret;
		std::string phone_number;
	public:
		//constructors
		Contact();
		Contact(const std::string& first_name, const std::string& last_name, const std::string& nick_name, const std::string& darkest_secret, const std::string& phone_number);

		//setters
		void setfirstname(const std::string first_name);
		void setlastname(const std::string last_name);
		void setnickname(const std::string nick_name);
		void setdarkestsecret(const std::string darkest_secret);
		void setphonenumber(const std::string phone_number);

		//getters
		std::string getfirstname() const;
		std::string getlastname() const;
		std::string getnickname() const;
		std::string getdarkestsecret() const;
		std::string getphonenumber() const;
};

#endif
