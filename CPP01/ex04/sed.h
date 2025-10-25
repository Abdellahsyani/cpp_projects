/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:40:42 by asyani            #+#    #+#             */
/*   Updated: 2025/10/25 18:43:15 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
#define SED_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::string filter_line(std::string line, std::string str1, std::string str2);
void get_values(std::vector<std::string> args);


#endif
