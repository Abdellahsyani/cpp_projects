/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:53:06 by asyani            #+#    #+#             */
/*   Updated: 2025/12/21 16:58:41 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


/**
 * Default Constructor: Initializes a generic Materia.
 * - Sets a placeholder type. Note: This is rarely used directly as 
 * derived classes (Ice/Cure) call the parameterized constructor.
 */
AMateria::AMateria() {
    type = "AMateria";
}

/**
 * Parameterized Constructor: The primary way to initialize Materia.
 * - Used by derived classes (Ice/Cure) to set their specific types.
 */
AMateria::AMateria(std::string const& type) : type(type) {}; 

/**
 * Copy Constructor: Duplicates the properties of another Materia.
 * - Ensures that the 'type' attribute is correctly carried over to the new instance.
 */
AMateria::AMateria(const AMateria& other) {
	this->type = other.type;
}

/**
 * Copy Assignment Operator: Synchronizes the state of two existing Materias.
 * - Uses a self-assignment guard to protect the object's integrity.
 */
AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/**
 * use: Provides a default behavior for Materia interaction.
 * - NOTE: This is a virtual method. While the base implementation does 
 * nothing (voiding the target to prevent unused parameter warnings), 
 * it is intended to be overridden by derived classes to provide 
 * specific spell effects (Polymorphism).
 */
void AMateria::use(ICharacter& target)
{
  (void)target;
}

/**
 * getType: this is the getter of the amateria class
 */
std::string const& AMateria::getType() const
{
	return this->type;
}


/**
 * Destructor: Cleans up the AMateria base components.
 * - CRITICAL: Must be marked 'virtual' in the header to ensure that 
 * when an AMateria* is deleted, the derived class destructor (Ice/Cure) 
 * is called first, preventing memory leaks.
 */
AMateria::~AMateria() {};
