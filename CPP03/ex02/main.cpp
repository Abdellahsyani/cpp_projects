/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:21:08 by asyani            #+#    #+#             */
/*   Updated: 2025/11/21 20:21:58 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main()
{
	ClapTrap clap("abdo");
	ScavTrap scav("bob");
	FragTrap frag("lion");

	clap.attack(scav.GetName());
	scav.attack(clap.GetName());
	frag.attack(scav.GetName());
	scav.takeDamage(10);
	frag.takeDamage(5);
	scav.beRepaired(2);
	frag.beRepaired(2);
	std::cout << "-------------------------------------" << std::endl;

	FragTrap frag1;
	ScavTrap scav1;
	frag1 = frag;
	scav1 = scav;
	frag1.highFivesGuys();
	std::cout << "-------------------------------------" << std::endl;

	return 0;
}
