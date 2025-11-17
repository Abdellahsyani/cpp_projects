/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:00:47 by asyani            #+#    #+#             */
/*   Updated: 2025/10/01 17:44:26 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA {
private:
	std::string name;
	Weapon &HumanA_weap;
public:
	HumanA(std::string name, Weapon &HumanA_weap);
	void	attack();
};
