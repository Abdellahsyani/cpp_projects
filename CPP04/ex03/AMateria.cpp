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
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
AMateria::AMateria() {
    type = "AMateria";
}

/**
 * Parametrize Constructor: This one take a parameter name to init the object
 */
AMateria::AMateria(std::string const& type) : type(type) {}; 

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Happens only when the object is being created
 *  	- behavior: b,a(b)
 */
AMateria::AMateria(const AMateria& other) {
	this->type = other.type;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/**
 * use: we just init this here to avoid linker error
 *      and also create vtable for it and for cleaning code
 *      but can't do anything here just default behavior
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
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
AMateria::~AMateria() {};
