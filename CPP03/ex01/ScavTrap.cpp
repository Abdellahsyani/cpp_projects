/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:23:47 by asyani            #+#    #+#             */
/*   Updated: 2025/11/28 18:50:27 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("")
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScaveTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap Parametrize Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
	if (this != other)
		ClapTrap::

}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "Copy assignement constructor called" << std::endl;
	if (this != other)
		ClapTrap::operator(this);
	return (*this);
}
