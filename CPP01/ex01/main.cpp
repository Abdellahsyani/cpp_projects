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
	int N = 4;
	Zombie *new_z = zombieHorde(N, "Foo");
	for (int i = 0; i < N; i++)
		new_z[i].announce();
	delete[] new_z;
	return 0;
}
