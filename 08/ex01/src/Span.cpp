/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:48:56 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/23 13:49:26 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _max_size(0) {}

Span::Span(unsigned int max_size) : _max_size(max_size) {}

Span::Span(const Span &other) : _vec(other._vec), _max_size(other._max_size) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    _vec = other._vec;
    _max_size = other._max_size;
    return (*this);
}
