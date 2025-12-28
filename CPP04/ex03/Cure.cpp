/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:21:58 by asyani            #+#    #+#             */
/*   Updated: 2025/12/21 16:55:33 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
Cure::Cure() : AMateria() {
    type = "cure";
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Happens only when the object is being created
 *  	- behavior: b,a(b)
 */
Cure::Cure(const Cure& other) : AMateria(other) {
	this->type = other.type;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
Cure Cure::operator=(const Cure& other) {
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

/**
 * use: This function print a message when the spell used to perform an action
 */
void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
} 

/**
 * clone: this function return a new Cure
 */
AMateria* Cure::clone() const {
  return new Cure;
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
Cure::~Cure() {};
