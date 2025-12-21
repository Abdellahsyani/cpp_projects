/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:34:40 by asyani            #+#    #+#             */
/*   Updated: 2025/12/15 19:47:57 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
Dog::Dog() : Animal() {
    std::cout << "Dog Default Constructor called" << std::endl;
    brain = new Brain();
}


/**
 * Parametrize Constructor: This called when an object created and init all member
 *  before the buddy constructor
 */
Dog::Dog(std::string type) : Animal(type) 
{
    std::cout << "Dog Parameterized Constructor called" << std::endl;
    brain = new Brain();
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Happens only when the object is being created
 *  	- behavior: b,a(b)
 */
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog Copy constructor called" << std::endl;
  this->brain = new Brain();

  *this->brain = *other.brain;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog Copy assignement constructor called" << std::endl;
	if (this != &other)
  {
		Animal::operator=(other);

    delete this->brain;

    this->brain = new Brain();
    *this->brain = *other.brain;
  }
	return (*this);
}

/**
 * makeSound: the method that make a sound depends on the object
 *  and this is a pure virtual function it create a vptr in v-table for each obj
 *   if I didn't implement it here this class will be abstract to
 */
void Dog::makeSound() const
{
	std::cout << "dog bark" << std::endl;
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
Dog::~Dog() { delete this->brain; std::cout << "Dog Destructor called" << std::endl; };
