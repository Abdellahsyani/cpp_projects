/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:15:41 by asyani            #+#    #+#             */
/*   Updated: 2025/11/11 12:00:11 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * - Operator >: check if the current object is greater the other
 *   - if greater: return true
 *   - return: false
 */
bool Fixed::operator>(const Fixed& other) const 
{
	if (this->Fixedpoint > other.Fixedpoint)
		return true;
	return false;
}

/**
 * - Operator <: check if the current object is smaller the other
 *   - if smaller: return true
 *   - return: false
 */
bool Fixed::operator<(const Fixed& other) const 
{
	if (this->Fixedpoint < other.Fixedpoint)
		return true;
	return false;
}

/**
 * - Operator >=: check if the left object >= from the right
 *   - return: true
 *   - return: false
 */
bool Fixed::operator>=(const Fixed& other) const {

	if (this->Fixedpoint >= other.Fixedpoint)
		return true;
	return false;
}

/**
 * - Operator <=: check if the left object <= from the right
 *   - return: true
 *   - return: false
 */
bool Fixed::operator<=(const Fixed& other) const {

	if (this->Fixedpoint <= other.Fixedpoint)
		return true;
	return false;
}

/**
 * - Operator !=: check if the left object != from the right
 *   - return: true
 *   - return: false
 */
bool Fixed::operator!=(const Fixed& other) const {

	if (this->Fixedpoint != other.Fixedpoint)
		return true;
	return false;
}

/**
 * - Operator ==: check if the left object == from the right
 *   - return: true
 *   - return: false
 */
bool Fixed::operator==(const Fixed& other) const {

	if (this->Fixedpoint == other.Fixedpoint)
		return true;
	return false;
}

/**
 * - Operator +: take the left object and add it to the right one
 *   - return: The sum of two objects
 */
Fixed Fixed::operator+(const Fixed& other) const {

	return this->Fixedpoint + other.Fixedpoint;
}

/**
 * - Operator -: take the left object and subtract it from the right one
 *   - return: The result
 */
Fixed Fixed::operator-(const Fixed& other) const {

	return this->Fixedpoint - other.Fixedpoint;
}

/**
 * - Operator /: take the left object and divide it on the right one
 *   - return: The results
 */
Fixed Fixed::operator/(const Fixed& other) const {

	return this->Fixedpoint / other.Fixedpoint;
}

/**
 * - Operator *: take the left object and multiply it by the right one
 *   - return: The results
 */
Fixed Fixed::operator*(const Fixed& other) const {

	return this->Fixedpoint * other.Fixedpoint;
}

/**
 * - Operator ++: Increase the fixed point
 *   - return: The result
 */
Fixed& Fixed::operator++() {
	Fixedpoint += 256;
	return *this;
}

/**
 * - Operator ++: Increase the fixed point
 *   - return: The result
 */
Fixed Fixed::operator++(int) {

	Fixed old = *this;
	Fixedpoint += 256;
	return old;
}

/**
 * - Operator --: decrease the fixed point
 *   - return: The result
 */
Fixed& Fixed::operator--() {
	Fixedpoint -= 256;
	return *this;
}

/**
 * - Operator ++: decrease the fixed point
 *   - return: The result
 */
Fixed Fixed::operator--(int) {

	Fixed old = *this;
	Fixedpoint -= 256;
	return old;
}
