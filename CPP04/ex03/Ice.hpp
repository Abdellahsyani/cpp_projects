/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:03:35 by asyani            #+#    #+#             */
/*   Updated: 2025/12/21 16:21:45 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

/**
 * Ice: A concrete implementation of the AMateria abstraction.
 *    * ROLE:
 *        Provides the "Ice Bolt" behavior. It implements the Prototype pattern 
 *        via clone(), allowing the system to duplicate Ice Materia without 
 *        knowing the concrete class type (Open/Closed Principle).
 *    * DECOUPLING:
 *        It interacts with the ICharacter interface rather than a concrete Character
 *        class, ensuring the spell can be used on any entity following the contract.
 **/
class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice &other);
	Ice& operator=(const Ice &other);
	~Ice();

	void use(ICharacter& target);
	AMateria* clone() const;
};
