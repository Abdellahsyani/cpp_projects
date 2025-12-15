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
	ClapTrap clap("abdo");
	ScavTrap scav("bob");

	clap.attack("bob");
	scav.attack("abdo");
	scav.takeDamage(4);
	scav.beRepaired(2);

	ClapTrap clap1;
	ScavTrap scav1;
	clap1 = clap;
	scav1 = scav;
	scav1.guardGate();

	return 0;
}
