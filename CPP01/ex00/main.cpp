/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:14:24 by asyani            #+#    #+#             */
/*   Updated: 2025/09/29 09:23:03 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie A("abdo"); 
	Zombie *el = newZombie("allo");
	randomChump("kaloc");
	el->announce();

	return 0;
}
