/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:06:39 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 14:35:04 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <typename T, typename Func>
void iter(T *array, size_t length, Func f) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}
