/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:11:30 by pgrossma          #+#    #+#             */
/*   Updated: 2024/12/09 21:30:37 by pgrossma         ###   ########.fr       */
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

uint PmergeMe::_getPairSize(uint level) {
    uint result = 1;
    for (uint i = 0; i < level; ++i) {
        result *= 2;
    }
    return result;
}

void PmergeMe::_insertLast(uint pairSize, uint level) {
    pairSize /= 2;

    size_t lastIndStart = _nbrs.size() - (_nbrs.size() % (pairSize * 2));
    size_t lastIndEnd = lastIndStart + pairSize;
    std::cout << "lastIndStart: " << lastIndStart << " lastIndEnd: " << lastIndEnd << std::endl;
    for (size_t i = pairSize - 1; i < _nbrs.size(); i += pairSize) {
        std::cout << "comparing " << _nbrs[lastIndStart] << " and " << _nbrs[i] << std::endl;
        if (_nbrs[lastIndEnd] < _nbrs[i]) {
            _nbrs.insert(_nbrs.begin() + i, _nbrs.begin() + lastIndStart, _nbrs.begin() + lastIndEnd);
            _nbrs.erase(_nbrs.end() - (_nbrs.size() % (pairSize * 2)) + 1, _nbrs.end() - (_nbrs.size() % (pairSize * 2)) + pairSize + 1);
            std::cout << "inserted " << _nbrs[lastIndEnd] << " at index " << i << std::endl;
            print(level);
            return;
        }
    }
}

void PmergeMe::_swapRange(uint a, uint b, uint size) {
    for (size_t i = 0; i < size; i++) {
        uint tmp = _nbrs[a - i];
        _nbrs[a - i] = _nbrs[b - i];
        _nbrs[b - i] = tmp;
        std::cout << "swapping ind " << a - i << " and " << b - i << " at size " << size << std::endl;
    }
}

void PmergeMe::_splitPairs(uint level) {
    uint pairSize = _getPairSize(level);
    if (_nbrs.size() / (pairSize / 2) < 2) {
        return;
    }

    std::cout << "before splitPairs at level " << level << " pairSize: " << pairSize << std::endl;

    for (size_t i = pairSize - 1; i < _nbrs.size(); i += pairSize) {
        uint a = _nbrs[i - pairSize / 2];
        uint b = _nbrs[i];
        std::cout << "comparing " << a << " and " << b << std::endl;
        if (a > b) {
            _swapRange(i - pairSize / 2, i, pairSize / 2);
            std::cout << "swapped " << a << " and " << b << " at level " << level << std::endl;
        }
    }
    std::cout << "after splitPairs at level " << level << std::endl;
    print(level);
    _splitPairs(level + 1);
    _insertLast(pairSize, level);
}

void PmergeMe::sort() {
    _splitPairs(1);
}

void PmergeMe::print(uint level) {
    for (uint i = 0; i < _nbrs.size(); i++) {
        std::cout << _nbrs[i] << " ";
        if ((i + 1) % (_getPairSize(level) / 2) == 0) {
            std::cout << "|";
        }
    }
    std::cout << std::endl;
}
