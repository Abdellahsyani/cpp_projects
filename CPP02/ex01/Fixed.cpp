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
Fixed::Fixed() : Fixedpoint(0) {
	std::cout << "Default constructor called" << std::endl;
};

/**
 * - Paramitrize constructor: This one take int parameter
 *   - num: The number converted to fixed point
 *   - This constructor under overloading functions
 */
Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	Fixedpoint = num << frac_bit;
};

/**
 * - Paramitrize constructor: Take a float parameter
 *   - num: The float number that will converted to fixed point
 *   - This constructor under overloading functions
 */
Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	Fixedpoint = roundf(num * (1 << frac_bit));
};

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
 * - Insertion Operator: This one used to insert or send data to the output stream
 *   - os: The stream that will recieve the data
 *   - other: The data to be send
 */
std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return os;
}

/**
 * - The method to convert fixed point to float number
 *   - take fixed point and devide it by 256 to let it back to real number
 */
float Fixed::toFloat(void) const
{
	return ((float)Fixedpoint / (1 << frac_bit));
}

/**
 * - Method to convert fixed point to integer
 *   - Fixedpoint shifted by 8 and get the int number
 */
int Fixed::toInt(void) const 
{
	return Fixedpoint >> frac_bit;
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
	std::cout << "setRawBits member function called" << std::endl;
	this->Fixedpoint = raw;
}

/**
 * - Destructor: used to clean up after the other constructors
 */
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
