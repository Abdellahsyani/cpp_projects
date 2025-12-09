/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:14:31 by asyani            #+#    #+#             */
/*   Updated: 2025/12/09 22:20:53 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 *  - call ClapTrap constructor to init it before the scavtrap constructor
 */
FragTrap::FragTrap() : ClapTrap("")
{
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

/**
 * Parametrize Constructor: This called when an object created and init all member
 *  before the buddy constructor
 *  - call ClapTrap parametirze constructor to init it before the scavtrap constructor
 */
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "FragTrap Parametrize Constructor called" << std::endl;
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Heppens only when the object is bieng created
 *  	- behavior: b,  a(b)
 */
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap Copy assignement constructor called" << std::endl;
	return (*this);
}

/**
 * attack: a method to attack with
 *  - target: the target that will be attecked
 */
void FragTrap::attack(const std::string& target) {
	if (this->HitPoints == 0)
	{
		std::cout << "FragTrap " << this->Name << " is dead" << std::endl;
		return ;
	}
	if (this->EnergyPoints == 0)
	{
		std::cout << "FragTrap " << this->Name << " is out of energy and cannot attack!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->GetName() << " attacks " << target << ", causing " << this->AttackDamage << " points of damage" << std::endl;
	this->EnergyPoints -= 1;
}

/**
 * gaurdGate: The method that only inform that the scavTrap is in gate keeper mode
 */
void FragTrap::guardGate() {
	std::cout << "FragTrap " << this->Name << " is now in Gate keeper mode!" << std::endl;
}


/**
 * gaurdGate: The method that only inform that the scavTrap is in gate keeper mode
 */
void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->Name << " is requesting a high five" << std::endl;
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
FragTrap::~FragTrap() { std::cout << "FragTrap Destructor called" << std::endl; };
