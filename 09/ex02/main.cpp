/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:14:10 by pgrossma          #+#    #+#             */
/*   Updated: 2025/01/10 19:55:35 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <list>
#include <vector>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe numbers..." << std::endl;
        return (EXIT_FAILURE);
    }

    try {
        std::vector<std::string> args(argv + 1, argv + argc);

        PmergeMe<std::vector<uint>> pmergeMe(args);
        std::vector<uint> sorted = pmergeMe.sort();
        std::cout << "Before: ";
        for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::cout << "After: ";
        for (std::vector<uint>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

