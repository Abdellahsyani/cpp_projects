/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:15:28 by asyani            #+#    #+#             */
/*   Updated: 2025/10/25 18:45:25 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}

	std::string filename;
	std::string str1;
	std::string str2;
	filename = av[1];
	str1 = av[2];
	str2 = av[3];

	get_values(filename, str1, str2);
	return 0;
}
