/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:11:33 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/27 17:35:18 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: ./btc <inputfile>" << std::endl;
        return (EXIT_FAILURE);
    }

    BitcoinExchange btc;
    btc.lookUpValuesFromFile(argv[1]);

    return (EXIT_SUCCESS);
}
