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
#include "DiamondTrap.hpp"


int main()
{
	DiamondTrap diamond("alex");

	diamond.attack("abdo");
	diamond.whoAmI();
	std::cout << "-------------------------------------" << std::endl;


	return 0;
}
