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
	std::vector<std::string> args(av, av + ac);

	if (args.size() > 4 || args.size() <= 3)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	get_values(args);
	return 0;
}
