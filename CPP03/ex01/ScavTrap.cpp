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

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 *  - call ClapTrap constructor to init it before the scavtrap constructor
 */
ScavTrap::ScavTrap() : ClapTrap()
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

/**
 * Parametrize Constructor: This called when an object created and init all member
 *  before the buddy constructor
 *  - call ClapTrap parametirze constructor to init it before the scavtrap constructor
 */
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap Parametrize Constructor called" << std::endl;
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Heppens only when the object is bieng created
 *  	- behavior: b,  a(b)
 */
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap Copy assignement constructor called" << std::endl;
	return (*this);
}

/**
 * attack: a method to attack with
 *  - target: the target that will be attecked
 */
void ScavTrap::attack(const std::string& target) {
	if (this->HitPoints == 0)
	{
		std::cout << "ScavTrap " << this->Name << " is dead" << std::endl;
		return ;
	}
	if (this->EnergyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->Name << " is out of energy and cannot attack!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->GetName() << " attacks " << target << ", causing " << this->AttackDamage << " points of damage" << std::endl;
	this->EnergyPoints -= 1;
}

/**
 * gaurdGate: The method that only inform that the scavTrap is in gate keeper mode
 */
void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode!" << std::endl;
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor called" << std::endl; };
