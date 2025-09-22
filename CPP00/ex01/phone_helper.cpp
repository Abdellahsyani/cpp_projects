/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:50:00 by asyani            #+#    #+#             */
/*   Updated: 2025/09/15 18:50:09 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	read_line(std::string &str)
{
	std::getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cout << "\n\033[31mEOF detected, exiting...\033[0m" << std::endl;
		std::exit(0);
	}
}

int	choice_function(std::string& in)
{

	while (true)
	{
		std::cout << "Do you want to enter more contacts y/n: ";
		if (!std::getline(std::cin, in))
		{
			if (std::cin.eof())
			{
				std::cout << "\n\033[31mEOF detected, exiting...\033[0m" << std::endl;
				std::exit(0); 
			}
		}
		if (in.empty())
			continue;
		else if (in != "y" && in != "n")
			continue;
		else
			break;
	}
	if (in == "y")
		return 1;
	else if (in == "n")
		return 0;
	return -1;
}

std::string format_column(const std::string &s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

int is_valid_input(const std::string &s)
{
	if (s.empty())
	{
		std::cout << "\033[31m" <<"Field cannot be empty, try again" << "\033[0m" << std::endl;
		return 1;
	}

	for (char c : s)
	{
		if (c < 32 || c == 127)
		{
			std::cout << "\033[31m" <<"Invalid characters, try again" << "\033[0m" << std::endl;
			return 1;
		}
	}
	return 0;
}

void exit_phone(void)
{
	std::cout << "\033[32m" << R"(
  	 ____                 _ _                
  	/ ___| ___   ___   __| | |__  _   _  ___ 
 	| |  _ / _ \ / _ \ / _` | '_ \| | | |/ _ \
	 | |_| | (_) | (_) | (_| | |_) | |_| |  __/
  	\____|\___/ \___/ \__,_|_.__/ \__, |\___|
                                 |___/     
	)" << "\033[0m" << std::endl;
	std::exit(0);
}
