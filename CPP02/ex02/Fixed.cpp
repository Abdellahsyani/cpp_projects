/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:02:08 by asyani            #+#    #+#             */
/*   Updated: 2025/11/11 14:44:52 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac_bit = 8;

/**
 * - Default constructor: called when an object created
 *   - used initializer list
 */
Fixed::Fixed() : Fixedpoint(0) {};

/**
 * - Default constructor: This one take int parameter
 *   - num: The number converted to fixed point
 *   - This constructor under overloading functions
 */
Fixed::Fixed(const int num) {
	Fixedpoint = num << frac_bit;
};

/**
 * - Default constructor: Take a float parameter
 *   - num: The float number that will converted to fixed point
 *   - This constructor under overloading functions
 */
Fixed::Fixed(const float num) {
	Fixedpoint = (int)roundf(num * (1 << frac_bit));
};

/**
 * - Copy Constructor: Used to copy a new object from an existing one
 *   - other: The object that will copied
 */
Fixed::Fixed(const Fixed& other) {
	Fixedpoint = other.Fixedpoint;
}

/**
 * - Copy assignment operator: This copy an existing object to another exist one
 *   - other: The copied object
 */
Fixed& Fixed::operator=(const Fixed& other)
{
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
	return (float)Fixedpoint / (1 << frac_bit); 
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
 * - min: method to compare between two objects
 *   - return: the smallest one
 */
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a< b)
		return a;
	else
		return b;
}

/**
 * - min: method to compare between two const objects
 *   - return: the smallest one
 */
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	else
		return b;
}

/**
 * - max: method to compare between two objects
 *   - return: the greatest one
 */
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	else
		return b;
}

/**
 * - max: method to compare between two const objects
 *   - return: the greatest one
 */
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	else
		return b;
}

/**
 * - Destructor: used to clean up after the other constructors
 */
Fixed::~Fixed() {}
