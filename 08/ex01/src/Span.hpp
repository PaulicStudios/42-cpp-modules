/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:43:48 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/23 14:17:01 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <exception>
#include <algorithm>

class Span {
    private:
        std::vector<int> _vec;
        const unsigned int _maxSize;

        Span();
    public:
        Span(unsigned int max_size);
        Span(const Span &other);
        ~Span();
        Span &operator=(const Span &other);

        unsigned int maxSize() const;

        void addNumber(int number);
        int shortestSpan();
        int longestSpan();

        class AlreadyFullException : public std::exception {
            const char *what() const throw() {
                return ("Span is already full");
            }
        };

        class NotEnoughNumbersException : public std::exception {
            const char *what() const throw() {
                return ("Not enough numbers to calculate span");
            }
        };
};
