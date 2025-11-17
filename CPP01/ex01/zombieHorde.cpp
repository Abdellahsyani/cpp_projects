/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:19:01 by asyani            #+#    #+#             */
/*   Updated: 2025/09/30 16:34:56 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *new_zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
      		new_zombie[i].setName(name);
	return new_zombie;
}
