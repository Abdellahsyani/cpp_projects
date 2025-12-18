/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:00:17 by asyani            #+#    #+#             */
/*   Updated: 2025/12/18 22:03:22 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat Default Constructor called" << std::endl;
}


/**
 * Parametrize Constructor: This called when an object created and init all member
 *  before the buddy constructor
 */
WrongCat::WrongCat(std::string type) : WrongAnimal(type) 
{
    std::cout << "WrongCat Parameterized Constructor called" << std::endl;
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Happens only when the object is being created
 *  	- behavior: b,a(b)
 */
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat Copy assignement constructor called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

/**
 * makeSound: the method that make a sound depends on the object
 */
void WrongCat::makeSound() const
{
	std::cout << "cat's don't bark" << std::endl;
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
WrongCat::~WrongCat() { std::cout << "WrongCat Destructor called" << std::endl; };
