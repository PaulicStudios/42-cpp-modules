/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:27:27 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/20 16:30:59 by pgrossma         ###   ########.fr       */
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
    Type type = getType(literal);

    switch (type)
    {
        case CHAR:
            printFromChar(literal);
            break;
        case INT:
            printFromInt(literal);
            break;
        case FLOAT:
            printFromFloat(literal);
            break;
        case DOUBLE:
            printFromDouble(literal);
            break;
    }
}

ScalarConverter::Type ScalarConverter::getType(const std::string &literal)
{
    if (literal.length() == 1 && literal[0] >= 32 && literal[0] <= 126)
        return (CHAR);
    return (INT);
}

void ScalarConverter::printFromChar(const std::string &literal)
{
    char c = literal[0];

    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printFromInt(const std::string &)
{
    
}

void ScalarConverter::printFromFloat(const std::string &)
{

}

void ScalarConverter::printFromDouble(const std::string &)
{

}
