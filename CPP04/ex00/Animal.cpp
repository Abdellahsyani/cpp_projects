/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:15:31 by asyani            #+#    #+#             */
/*   Updated: 2025/12/15 19:47:52 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
Animal::Animal() {
    std::cout << "Animal Default Constructor called" << std::endl;
    type = "Animal";
}


/**
 * Parametrize Constructor: This called when an object created and init all member
 *  before the buddy constructor
 */
Animal::Animal(std::string type) : type(type) 
{
    std::cout << "Animal Parameterized Constructor called" << std::endl;
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Happens only when the object is being created
 *  	- behavior: b,a(b)
 */
Animal::Animal(const Animal& other) {
	std::cout << "Animal Copy constructor called" << std::endl;
	this->type = other.type;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal Copy assignement constructor called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/***/
void Animal::makeSound()
{
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
Animal::~Animal() { std::cout << "Animal Destructor called" << std::endl; };
