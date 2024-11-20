/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:26:23 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/20 16:06:58 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ScalarConverter {
    private:
        static void print_char(const std::string &literal);
    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &ScalarConverter);
        ScalarConverter &operator=(ScalarConverter const &ScalarConverter);
        ~ScalarConverter();

        static void convert(const std::string &literal);
};
