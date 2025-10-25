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
#include <fstream>


void filter_line(std::string file, std::string line, std::string str1, std::string str2)
{
	std::string filename = file + ".replace";
	std::ofstream file(filename, std::ios::app);
	if (!filename.is_open())
	{
		std::cout << "Error: can't open this file" << std::endl;
		return;
	}
	size_t pos = 0;
	size_t found;
	std::string new_line;
	while ((found = line.find(str1, pos)) != std::string::npos)
	{
		new_line += line.substr(pos, found - pos);
		new_line += str2;
		found += str1.length();
	}
	new_line += line.substr(pos);
	std::cout << new_line << std::endl;
}

void get_values(std::vector<std::string> args)
{
	std::string filename;
	std::string str1;
	std::string str2;
	std::ifstream file;
	std::string line;

	filename = args[1];
	str1 = args[2];
	str2 = args[3];
	file.open(filename);
	if (!file.is_open())
	{
		std::cerr << "File failed to open" << std::endl;
		return;
	}
	
	while (std::getline(file, line))
		filter_line(filename, line, str1, str2);
}

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
