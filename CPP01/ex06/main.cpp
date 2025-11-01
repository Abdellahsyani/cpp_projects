/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:01:57 by asyani            #+#    #+#             */
/*   Updated: 2025/10/28 19:02:55 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	std::string level = av[1];
	Harl harl;

	harl.complain(level);
	return 0;
}
