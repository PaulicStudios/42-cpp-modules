/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:11:33 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/28 19:26:21 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc <inputfile>" << std::endl;
        return (EXIT_FAILURE);
    }

    try
    {
        BitcoinExchange btc;
        btc.lookUpValuesFromFile(argv[1]);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (EXIT_SUCCESS);
}
