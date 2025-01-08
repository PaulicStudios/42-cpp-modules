/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:11:30 by pgrossma          #+#    #+#             */
/*   Updated: 2025/01/08 13:15:11 by pgrossma         ###   ########.fr       */
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

void PmergeMe::_swapRange(std::vector<uint> &vec, uint start, uint end, uint size) {
    for (uint i = 0; i < size; i++) {
        std::swap(vec[start + i], vec[end + i]);
    }
}

void PmergeMe::_splitPairs(uint level) {
    if (_nbrs.size() / level < 2) {
        return;
    }

    for (uint i = 0; i < _nbrs.size(); i += level * 2) {
        if (i + level * 2 <= _nbrs.size()) {
            if (_nbrs[i] > _nbrs[i + level]) {
                _swapRange(_nbrs, i, i + level, level);
            }
        }
    }
    _splitPairs(level * 2);
}

void PmergeMe::sort() {
    _splitPairs(1);
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
