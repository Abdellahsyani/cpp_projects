/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:46:26 by asyani            #+#    #+#             */
/*   Updated: 2025/10/01 16:52:24 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon {
private:
	std::string type;
public:
	Weapon(std::string type);
	std::string getType() const;
	void setType(const std::string& type);
};
