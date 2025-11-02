/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:03:06 by asyani            #+#    #+#             */
/*   Updated: 2025/10/28 19:42:41 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ) {
		std::cout << "[ DEBUG ] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
};

void Harl::info( void ) {
		   std::cout << "[ INFO ] I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};

void Harl::warning( void ) {
	std::cout << "[ WARNING ] I think I deserve to have some extra bacon for free. I’ve been coming for \
years, whereas you started working here just last month." << std::endl;
}

void Harl::error( void ) {
		std::cout << "[ ERROR ] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level ) {
	int n = -1;
	if (level == "DEBUG") n = 1;
	else if (level == "INFO") n = 2;
	else if (level == "WARNING") n = 3;
	else if (level == "ERROR") n = 4;

	switch (n)
	{
		case 1:
			this->debug();
		case 2:
			this->info();
		case 3:
			this->warning();
		case 4:
			this->error();
		default:
			std::cout << "Unknown command" << std::endl;
		break;
	}
}
