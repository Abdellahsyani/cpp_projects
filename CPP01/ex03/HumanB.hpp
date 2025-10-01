/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:13:04 by asyani            #+#    #+#             */
/*   Updated: 2025/10/01 17:13:43 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
	std::string name;
	Weapon *H_weap;
public:
	HumanB(std::string name);
	void	setWeapon(Weapon& H_weap);
	void	attack();
};
