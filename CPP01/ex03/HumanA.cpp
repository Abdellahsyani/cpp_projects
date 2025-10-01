/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:06:42 by asyani            #+#    #+#             */
/*   Updated: 2025/10/01 17:11:49 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon HumanA_weap) :
	name(name), HumanA_weap(HumanA_weap) {};

void HumanA::attack() {
	std::cout << this->name << " attacks with their "
		<< this->HumanA_weap.getType() << std::endl;
}
