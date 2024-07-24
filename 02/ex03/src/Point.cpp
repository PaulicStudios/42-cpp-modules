/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:19:13 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/24 18:46:12 by pgrossma         ###   ########.fr       */
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

static Fixed	area(const Point a, const Point b, const Point c)
{
	Fixed area = a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());
	if (area < 0)
		area = area * -1;
	return (area);
}

bool	Point::bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed total_area = area(a, b, c);
	Fixed area1 = area(a, b, point);
	Fixed area2 = area(b, c, point);
	Fixed area3 = area(c, a, point);

	return (total_area == area1 + area2 + area3);
}
