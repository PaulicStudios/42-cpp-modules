/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:28:56 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/20 16:12:19 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return (EXIT_FAILURE);
    }

    ScalarConverter::convert(argv[1]);

    return (EXIT_SUCCESS);
}
