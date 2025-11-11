/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:49:35 by asyani            #+#    #+#             */
/*   Updated: 2025/11/11 13:40:47 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <ostream>

class Fixed {
private:
	int Fixedpoint;
	static const int frac_bit;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);
