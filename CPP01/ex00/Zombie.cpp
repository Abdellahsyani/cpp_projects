/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:15:28 by asyani            #+#    #+#             */
/*   Updated: 2025/09/29 09:16:08 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {};

Zombie::~Zombie() {
	std::cout << this->name << ": Zombie is destroyed" << std::endl;
}


void Zombie::announce(void) {
	if (this->name == "Foo")
		std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
	else
		std::cout << "<" << this->name << ">" << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}
