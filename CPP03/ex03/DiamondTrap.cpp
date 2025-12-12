/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:38:00 by asyani            #+#    #+#             */
/*   Updated: 2025/12/10 18:52:06 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 *  - call ClapTrap constructor to init it before the scavtrap constructor
 */
DiamondTrap::DiamondTrap() : ScavTrap(""), FragTrap("")
{
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

/**
 * Parametrize Constructor: This called when an object created and init all member
 *  before the buddy constructor
 *  - call ClapTrap parametirze constructor to init it before the scavtrap constructor
 */
DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 30;
	std::cout << "DiamondTrap Parametrize Constructor called" << std::endl;
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Heppens only when the object is bieng created
 *  	- behavior: b,  a(b)
 */
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ScavTrap(other), FragTrap(other) {
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other)
	{
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
	}
	std::cout << "DiamondTrap Copy assignement constructor called" << std::endl;
	return (*this);
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap Destructor called" << std::endl; };
