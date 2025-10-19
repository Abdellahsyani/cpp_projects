/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:15:28 by asyani            #+#    #+#             */
/*   Updated: 2025/10/04 16:19:35 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>


void get_values(std::vector<std::string> args)
{
	std::string filename;
	std::string str1;
	std::string str2;

	filename = args[1];
	std::cout << filename << std::endl;
	str1 = args[2];
	std::cout << str1 << std::endl;
	str2 = args[3];
	std::cout << str2 << std::endl;
}

int main(int ac, char **av)
{
	std::vector<std::string> args(av, av + ac);

	if (args.size() > 4 || args.size() < 3)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	get_values(args);
	return 0;
}
