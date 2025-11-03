/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:33:59 by asyani            #+#    #+#             */
/*   Updated: 2025/11/03 09:34:01 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (add.empty())
				continue;
			std::cout << "\033[31m" << "Error: only (ADD | SEARCH | EXIT) allowed" << "\033[0m" << std::endl;
			continue;
		}
	}

	return (0);
}
