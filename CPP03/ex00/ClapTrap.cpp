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
ClapTrap::ClapTrap() { std::cout << "Default constructor called" << std::endl; };


/**
 * Parametrize Constructor: This one called when the object is created
 *  - initiliaze all class memeber by using list initializer
 *  	before the buddy constructor
 */
ClapTrap::ClapTrap(std::string Name, int HitPoints, int	EnergyPoints, int AttackDamage) :
	Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) { std::cout << "Parametrize Constructor called" << std::endl; };

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Heppens only when the object is bieng created
 *  	- behavior: b,  a(b)
 */
ClapTrap::ClapTrap(const ClapTrap& other) {
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
	this->name = name;
}

/**
 * GetName: This is the getter to get the name
 * - name: the name to be getted from the class
 */
std::string ClapTrap::GetName() const {
	return this->name;
}

/**
 * attack: a method to attack with
 *  - target: the target that will be attecked
 */
void ClapTrap::attack(const std::string& target) {
	//start method
	if (this->hitpoints == 0  || this->EnergyPoints == 0)
	{
		std::cout << "ClapTrap is dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->GetName() << " attacks " << target << ", causing " << this->AttackDamage << "points of damage" << std::endl;
	this->EnergyPoints =- 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	// start method
	if (this->EnergyPoints == 0)
	{
		std::cout << "ClapTrap is dead" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->GetName() << " takedamage" << std::endl; 
	this->hitpoints =- amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	// start method
	if (this->hitpoints == 0 || this->EnergyPoints == 0)
	{
		std::cout << "ClapTrap cannot repair" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->GetName() << " beRepaired" << std::endl; 
	this->hitpoints =+ amount;
	this->EnergyPoints =- 1;
}
