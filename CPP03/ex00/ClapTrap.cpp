/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:26:22 by asyani            #+#    #+#             */
/*   Updated: 2025/11/20 13:18:25 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {};

ClapTrap::ClapTrap(std::string Name, int HitPoints, int	EnergyPoints, int AttackDamage) :
	Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) {};

void ClapTrap::attack(const std::string& target) {
	//start method
}

void ClapTrap::takeDamage(unsigned int amount) {
	// start method
}

void ClapTrap::beRepaired(unsigned int amount) {
	// start method
}
