/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:27:27 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/20 19:45:54 by pgrossma         ###   ########.fr       */
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
    if (literal == "+inff" || literal == "-inff" || literal == "nanf")
        return (FLOAT);
    if (literal == "+inf" || literal == "-inf" || literal == "nan")
        return (DOUBLE);

    if (literal.length() == 1 && literal[0] >= 32 && literal[0] <= 126 && !std::isdigit(literal[0]))
        return (CHAR);
    if (literal.find('.') == std::string::npos)
        return (INT);
    if (literal.find('f') != std::string::npos)
        return (FLOAT);
    return (DOUBLE);
}

void ScalarConverter::printFromChar(const std::string &literal)
{
    char c = literal[0];

    printChar(c);
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printFromInt(const std::string &literal)
{
    int i;

    try
    {
        i = std::stoi(literal);
    }
    catch (std::exception &e)
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }

    if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
        std::cout << "char: impossible" << std::endl;
    else
        printChar(static_cast<char>(i));
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::printFromFloat(const std::string &literal)
{
    float f;

    if (literal == "+inff")
        f = std::numeric_limits<float>::infinity();
    else if (literal == "-inff")
        f = -std::numeric_limits<float>::infinity();
    else if (literal == "nanf")
        f = std::numeric_limits<float>::quiet_NaN();
    else
    {
        try
        {
            f = std::stof(literal);
        }
        catch (std::exception &e)
        {
            std::cout << "float: impossible" << std::endl;
            return;
        }
    }

    if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
        std::cout << "char: impossible" << std::endl;
    else
        printChar(static_cast<char>(f));
    if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printFromDouble(const std::string &literal)
{
    double d;

    if (literal == "+inf")
        d = std::numeric_limits<double>::infinity();
    else if (literal == "-inf")
        d = -std::numeric_limits<double>::infinity();
    else if (literal == "nan")
        d = std::numeric_limits<double>::quiet_NaN();
    else
    {
        try
        {
            d = std::stod(literal);
        }
        catch (std::exception &e)
        {
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
        std::cout << "char: impossible" << std::endl;
    else
        printChar(static_cast<char>(d));
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printChar(const char &c)
{
    if (c >= 32 && c <= 126)
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}
