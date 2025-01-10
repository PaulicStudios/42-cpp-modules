/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:14:10 by pgrossma          #+#    #+#             */
/*   Updated: 2025/01/10 18:14:19 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe numbers..." << std::endl;
        return (EXIT_FAILURE);
    }

    try {
        std::vector<std::string> args(argv + 1, argv + argc);
        PmergeMe pmergeMe(args);
        std::vector<uint> sorted = pmergeMe.sort();
        std::cout << "Before: ";
        for (uint i = 0; i < args.size(); i++) {
            std::cout << args[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "After: ";
        for (uint i = 0; i < sorted.size(); i++) {
            std::cout << sorted[i] << " ";
        }
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

