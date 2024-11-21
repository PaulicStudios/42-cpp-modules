/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:40:28 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 14:59:39 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <typename T>
class Array {
    private:
        T *_array;
        unsigned int _size;

    public:
        Array() : _array(nullptr), _size(0) {}

        Array(unsigned int n) : _array(new T[n]), _size(n) {}

        Array(const Array &other) : _array(new T[other._size]), _size(other._size) {
            for (size_t i = 0; i < _size; i++) {
                _array[i] = other._array[i];
            }
        }

        Array &operator=(const Array &other) {
            delete[] _array;
            _array = new T[other._size];
            _size = other._size;
            for (size_t i = 0; i < _size; i++) {
                _array[i] = other._array[i];
            }
            return *this;
        }

        ~Array() {
            delete[] _array;
        }
};
