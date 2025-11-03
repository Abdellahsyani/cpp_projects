/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:33:46 by asyani            #+#    #+#             */
/*   Updated: 2025/11/03 09:33:48 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include "contact.hpp"
#include <limits>
#include <cstdlib>
#include <fstream>

#define BLUE "\033[34m"
#define RESET "\033[0m"

class PhoneBook {
	public:
		static int counter;
		Contact contacts[8];
		PhoneBook();
};

void	start(PhoneBook &phone);
void	contact_search(PhoneBook phone);
void	exit_phone(void);
int	is_valid_input(const std::string &s);
std::string	format_column(const std::string &s);
int	choice_function(std::string& in);
void	read_line(std::string &str);
int	simple_atoi(std::string str);

#endif
