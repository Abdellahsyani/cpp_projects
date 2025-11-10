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

Fixed::Fixed() : Fixedpoint(0) { std::cout << "Default constructor called" << std::endl; };


Fixed::Fixed(const Fixed& other) {
	Fixedpoint = other.Fixedpoint;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->Fixedpoint = other.Fixedpoint;
	return (*this);
}

int Fixed::getRawBits(void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->Fixedpoint;
}

void Fixed::setRawBits(const int raw)
{
	this->Fixedpoint = raw;
}


Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
