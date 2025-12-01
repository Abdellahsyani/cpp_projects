/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:40:01 by asyani            #+#    #+#             */
/*   Updated: 2025/10/25 18:45:15 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

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
		pos = found + str1.length();
	}
	new_line += line.substr(pos);
	return new_line;
}

void get_values(std::string filename, std::string str1, std::string str2)
{
	std::ifstream file;
	std::string line;

	if (str1.empty())
	{
		std::cout << "Error: s1 cannot be empty" << std::endl;
		return;
	}
	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "File failed to open" << std::endl;
		return;
	}
	
	std::string filena = filename + ".replace";
	std::ofstream file_rep(filena.c_str(), std::ios::out | std::ios::trunc);
	if (!file_rep.is_open())
	{
		std::cout << "Error: can't open this file" << std::endl;
		file.close();
		return;
	}
	std::string all_str;
	while (std::getline(file, line))
		file_rep << filter_line(line, str1, str2);
	file_rep.close();
	file.close();
}
