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


int main()
{
	ClapTrap clap;
	ScavTrap scav;

	clap.SetName("abdo");
	scav.SetName("smail");
	std::cout << scav.geten() << std::endl;
	std::cout << scav.getp() << std::endl;
	clap.attack("smail");
	scav.attack("abdo");
	scav.takeDamage(10);
	std::cout << scav.getp() << std::endl;
	std::cout << scav.geten() << std::endl;
	std::cout << clap.GetName() << std::endl;
	std::cout << scav.GetName() << std::endl;
	std::cout << "-------------------------------------" << std::endl;

	ClapTrap clap1;
	ScavTrap scav1;
	clap1 = clap;
	scav1 = scav;
	std::cout << clap1.GetName() << std::endl;
	std::cout << scav1.GetName() << std::endl;
	std::cout << "-------------------------------------" << std::endl;

	return 0;
}
