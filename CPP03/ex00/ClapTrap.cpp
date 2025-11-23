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

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	this->Name = other.Name;
	this->HitPoints = other.HitPoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;

	return *this;
}

void ClapTrap::SetName(const std::string name) {
	this->name = name;
}

std::string ClapTrap::GetName() const {
	return this->name;
}

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
