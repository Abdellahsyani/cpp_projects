/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:58:34 by asyani            #+#    #+#             */
/*   Updated: 2025/12/18 22:03:43 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal Default Constructor called" << std::endl;
    type = "WrongAnimal";
}


/**
 * Parametrize Constructor: This called when an object created and init all member
 *  before the buddy constructor
 */
WrongAnimal::WrongAnimal(std::string type) : type(type) 
{
    std::cout << "WrongAnimal Parameterized Constructor called" << std::endl;
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Happens only when the object is being created
 *  	- behavior: b,a(b)
 */
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	this->type = other.type;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "WrongAnimal Copy assignement constructor called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/**
 * getType: This method is the getter of the WrongAnimal class
 * it return the type;;
 */
std::string WrongAnimal::getType() const {
	return this->type;
}

/**
 * makeSound: the method that make a sound depends on the object
 */
void WrongAnimal::makeSound() const
{
	std::cout << "Generic WrongAnimal Sound" << std::endl;
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal Destructor called" << std::endl; };
