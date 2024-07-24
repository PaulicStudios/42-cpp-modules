/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:47:26 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/24 15:54:01 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Fixed {
	private:
		int					_nbr;
		static const int	_fractional_bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed &fixed);

		Fixed& operator=(const Fixed &fixed);
		Fixed operator+(const Fixed &right) const;
		Fixed operator-(const Fixed &right) const;
		Fixed operator*(const Fixed &right) const;
		Fixed operator/(const Fixed &right) const;

		bool operator>(const Fixed &right) const;
		bool operator<(const Fixed &right) const;
		bool operator>=(const Fixed &right) const;
		bool operator<=(const Fixed &right) const;
		bool operator==(const Fixed &right) const;
		bool operator!=(const Fixed &right) const;

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
