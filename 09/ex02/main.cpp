/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:14:10 by pgrossma          #+#    #+#             */
/*   Updated: 2025/01/11 13:42:00 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <deque>
#include <vector>
#include <chrono>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe numbers..." << std::endl;
        return (EXIT_FAILURE);
    }

    try {
        std::vector<std::string> args(argv + 1, argv + argc);

        // deque
        auto start = std::chrono::high_resolution_clock::now();
        PmergeMe<std::deque<uint>> pmergeMeDeque(args);
        std::deque<uint> sorted = pmergeMeDeque.sort();
        auto end = std::chrono::high_resolution_clock::now();
    
        std::cout << "Before: ";
        for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::cout << "After: ";
        for (std::deque<uint>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Time to process a range of " << args.size() << " elements with std::deque : " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;

        // vector
        start = std::chrono::high_resolution_clock::now();
        PmergeMe<std::vector<uint>> pmergeMeVector(args);
        std::vector<uint> sortedVector = pmergeMeVector.sort();
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Time to process a range of " << args.size() << " elements with std::vector : " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

