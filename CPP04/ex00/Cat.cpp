/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:29:23 by asyani            #+#    #+#             */
/*   Updated: 2025/12/15 19:39:46 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
Cat::Cat() : Animal("Cat") {
    std::cout << "Cat Default Constructor called" << std::endl;
}


/**
 * Parametrize Constructor: This called when an object created and init all member
 *  before the buddy constructor
 */
Cat::Cat(std::string type) : Animal(type) 
{
    std::cout << "Cat Parameterized Constructor called" << std::endl;
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Happens only when the object is being created
 *  	- behavior: b,a(b)
 */
Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat Copy constructor called" << std::endl;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Copy assignement constructor called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

/**
 * makeSound: the method that make a sound depends on the object
 */
void Cat::makeSound() const
{
	std::cout << "cat's don't bark" << std::endl;
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
Cat::~Cat() { std::cout << "Cat Destructor called" << std::endl; };
