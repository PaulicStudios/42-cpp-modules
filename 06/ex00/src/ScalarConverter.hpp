/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:26:23 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/20 19:16:49 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ScalarConverter {
    enum Type {
        CHAR,
        INT,
        FLOAT,
        DOUBLE
    };

    private:
        static Type getType(const std::string &literal);
        static void printFromChar(const std::string &literal);
        static void printFromInt(const std::string &literal);
        static void printFromFloat(const std::string &literal);
        static void printFromDouble(const std::string &literal);

        static void printChar(const char &c);

    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &ScalarConverter);
        ScalarConverter &operator=(ScalarConverter const &ScalarConverter);
        ~ScalarConverter();

        static void convert(const std::string &literal);
};
