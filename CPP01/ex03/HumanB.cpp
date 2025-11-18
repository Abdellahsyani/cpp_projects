/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:12:09 by asyani            #+#    #+#             */
/*   Updated: 2025/10/01 18:05:27 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
	name(name), H_weap(NULL) {};

void	HumanB::setWeapon(Weapon& H_weap) {
	this->H_weap = &H_weap;
}

void HumanB::attack() {
	if (H_weap) {
		std::cout << this->name << " attacks with their " << H_weap->getType() << std::endl;
	}
	else
		std::cout << "Error: " << this->name << " has no weapon to attack with" << std::endl;	
}
