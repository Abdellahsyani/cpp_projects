/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:52:52 by asyani            #+#    #+#             */
/*   Updated: 2025/10/28 10:10:02 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ) {
		std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
};

void Harl::info( void ) {
		   std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for \
years, whereas you started working here just last month." << std::endl;
}

void Harl::error( void ) {
		std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
