/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:21:52 by asyani            #+#    #+#             */
/*   Updated: 2025/12/21 16:21:54 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
Ice::Ice() : AMateria("ice") {}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Happens only when the object is being created
 *  	- behavior: b,a(b)
 */
Ice::Ice(const Ice& other) : AMateria(other) {
	this->type = other.type;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
Ice Ice::operator=(const Ice& other) {
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

/**
 * clone: this function take return a new Cure
 */
AMateria* Ice::clone() const {
  return new Ice;
}

/**
 * use: This function print a message when the spell used to perform an action
 */
void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
} 

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
Ice::~Ice() {};
