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


int main()
{
	ClapTrap obj;
	ClapTrap obj1;

	obj.SetName("abdo");
	obj1 = obj;
	ClapTrap obj2(obj1);
	obj1.SetName("izm");
	obj2.SetName("arro");
	obj.attack("rays");
	obj1.attack("abdo");
	obj2.attack("izm");

	obj.takeDamage(2);
	obj1.takeDamage(2);
	obj2.takeDamage(2);
	obj.beRepaired(3);
	obj1.beRepaired(3);
	obj2.beRepaired(3);
	return 0;
}
