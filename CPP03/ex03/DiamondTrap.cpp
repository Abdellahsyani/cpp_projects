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


#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 *  - call ClapTrap constructor to init it before the scavtrap constructor
 */
DiamondTrap::DiamondTrap() : ClapTrap("")
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
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "DiamondTrap Parametrize Constructor called" << std::endl;
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Heppens only when the object is bieng created
 *  	- behavior: b,  a(b)
 */
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other) {
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "DiamondTrap Copy assignement constructor called" << std::endl;
	return (*this);
}

/**
 * attack: a method to attack with
 *  - target: the target that will be attecked
 */
void DiamondTrap::attack(const std::string& target) {
	if (this->HitPoints == 0)
	{
		std::cout << "DiamondTrap " << this->Name << " is dead" << std::endl;
		return ;
	}
	if (this->EnergyPoints == 0)
	{
		std::cout << "DiamondTrap " << this->Name << " is out of energy and cannot attack!" << std::endl;
		return ;
	}
	std::cout << "DiamondTrap " << this->GetName() << " attacks " << target << ", causing " << this->AttackDamage << " points of damage" << std::endl;
	this->EnergyPoints -= 1;
}

/**
 * gaurdGate: The method that only inform that the scavTrap is in gate keeper mode
 */
void DiamondTrap::guardGate() {
	std::cout << "DiamondTrap " << this->Name << " is now in Gate keeper mode!" << std::endl;
}


/**
 * gaurdGate: The method that only inform that the scavTrap is in gate keeper mode
 */
void DiamondTrap::highFivesGuys() {
	std::cout << "DiamondTrap " << this->Name << " is requesting a high five" << std::endl;
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap Destructor called" << std::endl; };
