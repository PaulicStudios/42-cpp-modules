/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:43:48 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/23 13:47:51 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

class Span {
    private:
        std::vector<int> _vec;
        unsigned int _max_size;

        Span();
    public:
        Span(unsigned int max_size);
        Span(const Span &other);
        ~Span();
        Span &operator=(const Span &other);
};
