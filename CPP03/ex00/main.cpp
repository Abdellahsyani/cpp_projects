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

	obj.SetName("abdo");
	obj.attack("rays");
	obj.takeDamage(2);
	obj.takeDamage(2);
	obj.takeDamage(2);
	obj.takeDamage(2);
	obj.takeDamage(2);
	obj.takeDamage(2);
	return 0;
}
