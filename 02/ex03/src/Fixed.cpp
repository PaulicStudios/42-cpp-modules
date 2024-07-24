/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:24:57 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/24 18:47:51 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_nbr = 0;
}

Fixed::Fixed(const int nbr)
{
	_nbr = nbr << _fractional_bits;
}

Fixed::Fixed(const float nbr)
{
	_nbr = (int)roundf(nbr * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	_nbr = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	_nbr = fixed.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::~Fixed() {}

Fixed Fixed::operator+(const Fixed &right) const
{
	return (this->toFloat() + right.toFloat());
}

Fixed Fixed::operator-(const Fixed &right) const
{
	return (this->toFloat() - right.toFloat());
}

Fixed Fixed::operator*(const Fixed &right) const
{
	return (this->toFloat() * right.toFloat());
}

Fixed Fixed::operator/(const Fixed &right) const
{
	return (this->toFloat() / right.toFloat());
}

Fixed& Fixed::operator++()
{
	_nbr++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_nbr++;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	_nbr--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_nbr--;
	return (tmp);
}

bool Fixed::operator>(const Fixed &right) const
{
	return (this->toFloat() > right.toFloat());
}

bool Fixed::operator<(const Fixed &right) const
{
	return (this->toFloat() < right.toFloat());
}

bool Fixed::operator>=(const Fixed &right) const
{
	return (this->toFloat() >= right.toFloat());
}

bool Fixed::operator<=(const Fixed &right) const
{
	return (this->toFloat() <= right.toFloat());
}

bool Fixed::operator==(const Fixed &right) const
{
	return (this->getRawBits() == right.getRawBits());
}

bool Fixed::operator!=(const Fixed &right) const
{
	return (this->getRawBits() != right.getRawBits());
}

int Fixed::getRawBits() const
{
	return (_nbr);
}

void Fixed::setRawBits(int const raw)
{
	_nbr = raw;
}

int Fixed::toInt(void) const
{
	return (_nbr >> _fractional_bits);
}

float Fixed::toFloat(void) const
{
	return ((float)_nbr / (1 << _fractional_bits));
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a <= b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a <= b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a >= b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a >= b ? a : b);
}
