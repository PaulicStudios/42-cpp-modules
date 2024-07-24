/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:10:38 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/24 18:45:51 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	std::cout << "Is in the triangle: " << Point::bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(0.5, 0.5)) << std::endl;
	std::cout << "Is in the triangle: " << Point::bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 1)) << std::endl;
	return 0;
}
