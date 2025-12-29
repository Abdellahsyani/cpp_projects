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
 * ICharacter: This is an interface (all functions are pure virtual)
 *            we implemment this interface as contract if you want to be a Character you need
 *            to do these roles.
 *            In this situation the ICharacter create players to use spells that will created by using
 *            IMateriaSource interface
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
