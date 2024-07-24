/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:10:38 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/24 16:47:50 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c(3);
	Fixed d(2);

	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "c - d = " << c - d << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "c / d = " << c / d << std::endl;

	std::cout << "c > d " << (c > d) << std::endl;
	std::cout << "c < d " << (c < d) << std::endl;
	std::cout << "c >= d " << (c >= d) << std::endl;
	std::cout << "c <= d " << (c <= d) << std::endl;
	c = d;
	std::cout << "c == d " << (c == d) << std::endl;
	std::cout << "c != d " << (c != d) << std::endl;

	return 0;
}
