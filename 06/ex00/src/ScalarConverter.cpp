/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:27:27 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/20 16:16:25 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &ScalarConverter)
{
    *this = ScalarConverter;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &)
{
    return (*this);
}

ScalarConverter::~ScalarConverter() = default;

void ScalarConverter::convert(const std::string &literal)
{
    print_char(literal);
}

void ScalarConverter::print_char(const std::string &literal)
{
    std::cout << "char: ";
    try
    {
        char c = static_cast<char>(std::stoi(literal));

        if (c >= 32 && c <= 126)
            std::cout << c;
        else
            std::cout << "Non displayable";
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
}
