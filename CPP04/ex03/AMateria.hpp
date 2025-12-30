/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:57:48 by asyani            #+#    #+#             */
/*   Updated: 2025/12/21 16:58:50 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// forward declaration
class ICharacter;

/**
 * AMateria: An abstract base class representing a "Strategy" for spells.
 *    * ARCHITECTURE ROLE:
 *        This class serves as the Abstraction layer in the Dependency Inversion Principle (DIP).
 *        It creates a decoupled relationship between the Character (High-level) and 
 *        specific Materia types like Ice/Cure (Low-level).
 *    * DESIGN PATTERN:
 *        By using this interface, the system satisfies the Open/Closed Principle (OCP), 
 *        allowing new Materia types to be added without modifying existing Character 
 *        or Source logic.
 **/
class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
