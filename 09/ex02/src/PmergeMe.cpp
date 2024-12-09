/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:11:30 by pgrossma          #+#    #+#             */
/*   Updated: 2024/12/09 16:58:13 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<std::string> args) {
    for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); ++it) {
        try {
            uint nbr = std::stoi(*it);
            _nbrs.push_back(nbr);
        } catch (std::exception &e) {
            throw std::runtime_error("Invalid input");
        }
    }
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        this->_nbrs = src._nbrs;
    }
    return *this;
}

std::vector<std::pair<uint, uint>> PmergeMe::_initialPairs() {
    std::vector<std::pair<uint, uint>> pairs;
    for (size_t i = 0; i < _nbrs.size(); i++) {
        pairs.push_back(std::make_pair(0, _nbrs[i]));
    }
    return pairs;
}

std::vector<std::pair<uint, uint>> PmergeMe::_splitPairs(std::vector<std::pair<uint, uint>> pairs) {
    if (pairs.size() == 1)
        return pairs;

    std::vector<std::pair<uint, uint>> newPairs;
    for (size_t i = 0; i < pairs.size(); i += 2) {
        uint a = pairs[i].second;
        uint b = pairs[i + 1].second;
        if (a > b) {
            newPairs.push_back(std::make_pair(b, a));
        } else {
            newPairs.push_back(std::make_pair(a, b));
        }
    }

    uint *last = nullptr;
    if (pairs.size() % 2 == 1)
        last = &pairs.back().second;

    newPairs = _splitPairs(newPairs);

    return newPairs;
}

void PmergeMe::sort() {
    std::vector<std::pair<uint, uint>> pairs = _initialPairs();
    pairs = _splitPairs(pairs);
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << pairs[i].second << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::print() {
    for (std::vector<uint>::iterator it = _nbrs.begin(); it != _nbrs.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}