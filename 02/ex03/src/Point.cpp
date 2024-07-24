/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:19:13 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/24 18:26:44 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &point) : _x(point.getX()), _y(point.getY()) {}

Point& Point::operator=(Point &point)
{
	return (point);
}

Point::~Point() {}

Fixed	Point::getX() const
{
	return (_x);
}

Fixed	Point::getY() const
{
	return (_y);
}
