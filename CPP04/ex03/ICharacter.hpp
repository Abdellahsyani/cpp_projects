/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:48:01 by asyani            #+#    #+#             */
/*   Updated: 2025/12/21 16:48:47 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// forward declaration
class AMateria;

/**
 * ICharacter: A pure interface defining the "Character" contract.
 *    ** ARCHITECTURE:
 *        Every method is pure virtual (= 0), making this a strict Interface.
 *        It defines the API for any entity that needs to manage an inventory 
 *        and interact with Materia spells.
 *    ** INTERACTION:
 *        Provides the polymorphic hooks for the Character class. It allows 
 *        Materia (AMateria) to target players without knowing their concrete 
 *        type, facilitating loose coupling.
 **/
class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};
