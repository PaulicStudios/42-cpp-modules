/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:48:56 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/23 14:17:41 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int max_size) : _maxSize(max_size) {}

Span::Span(const Span &other) : _vec(other._vec), _maxSize(other._maxSize) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    _vec = other._vec;
    return (*this);
}

unsigned int Span::maxSize() const {
    return (_maxSize);
}

void Span::addNumber(int number) {
    if (_vec.size() >= _maxSize)
        throw AlreadyFullException();
    _vec.push_back(number);
}

int Span::shortestSpan() {
    if (_vec.size() < 2)
        throw NotEnoughNumbersException();

    if (!std::is_sorted(_vec.begin(), _vec.end()))
    std::sort(_vec.begin(), _vec.end());

    int shortest = std::abs(_vec[1] - _vec[0]);
    for (size_t i = 1; i < _vec.size() - 1; i++) {
        int span = std::abs(_vec[i + 1] - _vec[i]);
        if (span < shortest)
            shortest = span;
    }
    return (shortest);
}

int Span::longestSpan() {
    if (_vec.size() < 2)
        throw NotEnoughNumbersException();

    if (!std::is_sorted(_vec.begin(), _vec.end()))
        std::sort(_vec.begin(), _vec.end());

    return (std::abs(_vec.back() - _vec.front()));
}
