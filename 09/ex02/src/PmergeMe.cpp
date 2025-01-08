/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:11:30 by pgrossma          #+#    #+#             */
/*   Updated: 2025/01/08 17:23:09 by pgrossma         ###   ########.fr       */
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

void PmergeMe::_swapPairs(uint pair1, uint pair2, uint level) {
    for (uint i = 0; i < level; i++) {
        std::swap(_nbrs[pair1 - (level - 1) + i], _nbrs[pair2 - (level - 1) + i]);
    }
}

void PmergeMe::_sortPairs(uint level) {
    if (_nbrs.size() / level < 2) {
        return;
    }

    uint pairSize = level * 2;
    for (uint i = 0; i < _nbrs.size(); i += pairSize) {
        uint pair1 = i + level - 1;
        uint pair2 = i + pairSize - 1;
        if (pair2 >= _nbrs.size()) {
            break;
        }
        if (_nbrs[pair1] > _nbrs[pair2]) {
            _swapPairs(pair1, pair2, level);
        }
    }
    _sortPairs(level * 2);
}

void PmergeMe::sort() {
    _sortPairs(1);
    print(1);
}

void PmergeMe::print(uint level) {
    for (uint i = 0; i < _nbrs.size(); i++) {
        std::cout << _nbrs[i] << " ";
        (void)level;
        // if ((i + 1) % (_getPairSize(level) / 2) == 0) {
        //     std::cout << "| ";
        // }
    }
    std::cout << std::endl;
}
