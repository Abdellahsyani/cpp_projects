/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:02:08 by asyani            #+#    #+#             */
/*   Updated: 2025/11/09 15:26:30 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac_bit = 8;

/**
 * - Default constructor: called when an object created
 *   - used initializer list
 */
Fixed::Fixed() : Fixedpoint(0) { std::cout << "Default constructor called" << std::endl; };

/**
 * - Copy Constructor: Used to copy a new object from an existing one
 *   - other: The object that will copied
 */
Fixed::Fixed(const Fixed& other) {
	Fixedpoint = other.Fixedpoint;
	std::cout << "Copy constructor called" << std::endl;
}

/**
 * - Copy assignment operator: This copy an existing object to another exist one
 *   - other: The copied object
 */
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->Fixedpoint = other.Fixedpoint;
	return (*this);
}

/**
 * - A method to print fixedpoint
 *   - return: the fixedpoint
 */
int Fixed::getRawBits(void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->Fixedpoint;
}

/**
 * - A method to set fixedpoint
 */
void Fixed::setRawBits(const int raw)
{
	this->Fixedpoint = raw;
}

/**
 * - Destructor: used to clean up after the other constructors
 */
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
