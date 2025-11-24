/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:19:13 by asyani            #+#    #+#             */
/*   Updated: 2025/11/20 12:28:49 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap {
	private:
		std::string Name;
		int	HitPoints;
		int	EnergyPoints;
		int	AttackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& other);
		
		//setter
		void	SetName(const std::string name);

		//getter
		std::string GetName() const;


		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
