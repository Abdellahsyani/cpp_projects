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

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
ClapTrap::ClapTrap() :
    Name(""),
    HitPoints(10),
    EnergyPoints(10),
    AttackDamage(0) 
{
    std::cout << "ClapTrap Default Constructor called" << std::endl; 
}


/**
 * Parametrize Constructor: This called when an object created and init all member
 *  before the buddy constructor
 */
ClapTrap::ClapTrap(std::string name) : 
    Name(name), 
    HitPoints(10), 
    EnergyPoints(10), 
    AttackDamage(0) 
{
    std::cout << "ClapTrap Parameterized Constructor called for " << Name << std::endl;
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Heppens only when the object is bieng created
 *  	- behavior: b,  a(b)
 */
ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->Name = other.Name;
	this->HitPoints = other.HitPoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignement constructor called" << std::endl;
	this->Name = other.Name;
	this->HitPoints = other.HitPoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;

	return (*this);
}

/**
 * SetName: this is setter of attribute name
 *  - name: The name to be setted
*/
void ClapTrap::SetName(const std::string name) {
	this->Name = name;
}

/**
 * GetName: This is the getter to get the name
 * - name: the name to be getted from the class
 */
std::string ClapTrap::GetName() const {
	return this->Name;
}

/**
 * attack: a method to attack with
 *  - target: the target that will be attecked
 */
void ClapTrap::attack(const std::string& target) {
	if (this->HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->Name << " is dead" << std::endl;
		return ;
	}
	if (this->EnergyPoints == 0)
	{
		std::cout << "ClapTrap " << this->Name << " is out of energy and cannot attack!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->GetName() << " attacks " << target << ", causing " << this->AttackDamage << " points of damage" << std::endl;
	this->EnergyPoints -= 1;
}

/**
 * takedamage: The method that take damage when attack happen
 *  - amount: the amount that will add
 */
void ClapTrap::takeDamage(unsigned int amount) {
	if (this->EnergyPoints == 0)
	{
		std::cout << "ClapTrap " << this->Name << " is out of energy and cannot attack!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->GetName() << " takedamage" << std::endl; 
	if (this->HitPoints == 0)
	{
		this->HitPoints = 0;
		std::cout << "ClapTrap " << this->Name << " is already dead" << std::endl;
		return;
	}
	else
		this->HitPoints -= amount;
}

/**
 * beRepaired: method to be repair when the energey is low
 *  - amount: the amount to be repair with
 */
void ClapTrap::beRepaired(unsigned int amount) {
	// start method
	if (this->HitPoints == 0 || this->EnergyPoints == 0)
	{
		std::cout << "ClapTrap cannot repair" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->GetName() << " beRepaired" << std::endl; 
	this->HitPoints += amount;
	this->EnergyPoints -= 1;
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
ClapTrap::~ClapTrap() { std::cout << "Destructor called" << std::endl; };
