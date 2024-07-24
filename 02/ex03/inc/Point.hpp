/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:15:13 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/24 18:36:32 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		~Point();
		Point(const float x, const float y);
		Point(const Point &point);
		Point& operator=(Point &point);

		Fixed getX() const;
		Fixed getY() const;

		static bool bsp(const Point a, const Point b, const Point c, const Point point);
};
