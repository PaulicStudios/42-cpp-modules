/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:46:24 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/23 15:17:15 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack &other) : std::stack<T>(other) {}
        ~MutantStack() {}
        MutantStack &operator=(const MutantStack &other) {
            std::stack<T>::operator=(other);
            return (*this);
        }

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() {
            return (std::stack<T>::c.begin());
        }
        iterator end() {
            return (std::stack<T>::c.end());
        }
};
