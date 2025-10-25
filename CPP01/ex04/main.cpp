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
#include <string>

std::string filter_line(std::string line, std::string str1, std::string str2)
{
	size_t pos = 0;
	size_t found;
	std::string new_line;
	line += "\n";
	while ((found = line.find(str1, pos)) != std::string::npos)
	{
		new_line += line.substr(pos, found - pos);
		new_line += str2;
		pos += found + str1.length();
	}
	new_line += line.substr(pos);
	return new_line;
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
	
	std::string filena = filename + ".replace";
	std::ofstream file_rep(filena, std::ios::out | std::ios::trunc);
	if (!file_rep.is_open())
	{
		std::cout << "Error: can't open this file" << std::endl;
		return;
	}
	while (std::getline(file, line))
		file_rep << filter_line(line, str1, str2);
	file_rep.close();
	file.close();
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
