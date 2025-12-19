/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:17:18 by asyani            #+#    #+#             */
/*   Updated: 2025/12/19 16:18:56 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
Brain::Brain() {
  std::cout << "Brain Default Constructor called" << std::endl;
  for (int i = 0; i < 100; i++)
  {
    this->ideas[i] = "I have no idea yet...";
  }
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Happens only when the object is being created
 *  	- behavior: b,a(b)
 */
Brain::Brain(const Brain& other) {
  std::cout << "Brain Copy constructor called" << std::endl;
  for (int i = 0; i < 100; i++)
  {
    this->ideas[i] = other.ideas[i];
  }
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
Brain& Brain::operator=(const Brain& other) {
  std::cout << "Brain Copy assignement constructor called" << std::endl;
  if (this != &other)
  {
    for (int i = 0; i < 100; i++)
    {
      this->ideas[i] = other.ideas[i];
    }
  }
  return (*this);
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
Brain::~Brain() { std::cout << "Brain Destructor called" << std::endl; };
