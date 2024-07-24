/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:24:57 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/24 16:08:48 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_nbr = 0;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	_nbr = nbr << _fractional_bits;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	_nbr = (int)roundf(nbr * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	_nbr = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assigment operator called" << std::endl;
	_nbr = fixed.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	Fixed::operator+(const Fixed &right) const
{
	return (this->toFloat() + right.toFloat());
}

Fixed	Fixed::operator-(const Fixed &right) const
{
	return (this->toFloat() - right.toFloat());
}

Fixed	Fixed::operator*(const Fixed &right) const
{
	return (this->toFloat() * right.toFloat());
}

Fixed	Fixed::operator/(const Fixed &right) const
{
	return (this->toFloat() / right.toFloat());
}

bool	Fixed::operator>(const Fixed &right) const
{
	return (this->toFloat() > right.toFloat());
}

bool	Fixed::operator<(const Fixed &right) const
{
	return (this->toFloat() < right.toFloat());
}

bool	Fixed::operator>=(const Fixed &right) const
{
	return (this->toFloat() >= right.toFloat());
}

bool	Fixed::operator<=(const Fixed &right) const
{
	return (this->toFloat() <= right.toFloat());
}

bool	Fixed::operator==(const Fixed &right) const
{
	return (this->getRawBits() == right.getRawBits());
}

bool	Fixed::operator!=(const Fixed &right) const
{
	return (this->getRawBits() != right.getRawBits());
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_nbr);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_nbr = raw;
}

int	Fixed::toInt(void) const
{
	return (_nbr >> _fractional_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)_nbr / (1 << _fractional_bits));
}
