/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:34:51 by asyani            #+#    #+#             */
/*   Updated: 2025/11/03 09:34:57 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstring>

char to_upper(char c)
{
	if (c >= 'a' || c <= 'z')
		c -= 32;
	return c;
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	while (argv[i])
	{
		int j = 0;
		while (argv[i][j])
		{
			if (islower(argv[i][j]))
				std::cout << to_upper(argv[i][j]);
			else
				std::cout << argv[i][j];
			j++;
		}
		i++;
	}
	std::cout << "\n";
	return 0;
}
