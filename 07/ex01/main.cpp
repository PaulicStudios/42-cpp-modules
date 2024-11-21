/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:50:17 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 14:33:57 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

#include <iostream>

static void printIntArray(int *array, size_t length) {
    for (size_t i = 0; i < length; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

static void printStringArray(std::string *array, size_t length) {
    for (size_t i = 0; i < length; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
    int array[] = {1, 2, 3, 4, 5};

    std::cout << "Before: ";
    printIntArray(array, 5);

    iter(array, 5, [](int &a) { a *= 2; });

    std::cout << "After: ";
    printIntArray(array, 5);

    std::string strings[] = {"42", "Heilbronn"};

    std::cout << "Before: ";
    printStringArray(strings, 2);

    iter(strings, 2, [](std::string &a) { a += "!"; });

    std::cout << "After: ";
    printStringArray(strings, 2);

    return 0;
}
