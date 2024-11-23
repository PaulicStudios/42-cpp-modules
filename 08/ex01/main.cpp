/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:50:17 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/23 14:44:44 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
    {
        std::cout << "Test with iterator" << std::endl;
        Span span(10);
        std::vector<int> vec(11);
        for (unsigned int i = 0; i < vec.size(); i++)
            vec[i] = i;
        try {
            span.addNumber(vec.begin(), vec.end());
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }

        vec.resize(10);
        span.addNumber(vec.begin(), vec.end());
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "Test with 0 numbers expected to throw exception" << std::endl;
        Span span(0);

        try
        {
            span.addNumber(1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            std::cout << span.shortestSpan() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            std::cout << span.longestSpan() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "Test provided by subject" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "Test with 100.000 numbers" << std::endl;
        Span span(100000);

        std::srand(std::time(nullptr));
        for (unsigned int i = 0; i < span.maxSize(); i++)
            span.addNumber(std::rand());

        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }

    return (0);
}
