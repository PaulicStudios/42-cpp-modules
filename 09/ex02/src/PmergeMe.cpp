/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:11:30 by pgrossma          #+#    #+#             */
/*   Updated: 2024/12/10 11:11:17 by pgrossma         ###   ########.fr       */
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

size_t PmergeMe::_getPairSize(uint level) {
    size_t result = 1;
    for (uint i = 0; i < level; ++i) {
        result *= 2;
    }
    return result;
}

void PmergeMe::_insertLast(uint pairSize, uint level) {
    pairSize /= 2;
    if (_nbrs.size() % pairSize > pairSize / 2)
        return;

    size_t lastIndStart = _nbrs.size() - (_nbrs.size() % pairSize) - 1;
    std::cout << "lastIndStart: " << lastIndStart << " nbr: " << _nbrs[lastIndStart] << " at level " << level << std::endl;
    for (size_t i = pairSize - 1; i < _nbrs.size(); i += pairSize) {
        std::cout << "comparing " << _nbrs[lastIndStart] << " and " << _nbrs[i] << std::endl;
        if (_nbrs[lastIndStart] < _nbrs[i]) {
            _nbrs.insert(_nbrs.begin() + i - pairSize + 1, _nbrs.begin() + lastIndStart + 1, _nbrs.begin() + lastIndStart + pairSize + 1);
            _nbrs.erase(_nbrs.begin() + lastIndStart + 1, _nbrs.begin() + lastIndStart + pairSize + 1);
            print(level);
            std::cout << "swapped " << _nbrs[lastIndStart] << " and " << _nbrs[i] << std::endl;
        }
    }
}

void PmergeMe::_swapRange(size_t a, size_t b, size_t size) {
    for (size_t i = 0; i < size; i++) {
        uint tmp = _nbrs[a - i];
        _nbrs[a - i] = _nbrs[b - i];
        _nbrs[b - i] = tmp;
        // std::cout << "swapping ind " << a - i << " and " << b - i << " at size " << size << std::endl;
    }
}

void PmergeMe::_sortLevel(uint level, uint pairSize) {
    pairSize /= 2;
    if (_nbrs.size() % pairSize > pairSize / 2)
        return;

    std::cout << "sorting level " << level << " pairSize: " << pairSize << std::endl;
    
    std::vector<uint> sorted;
    sorted.insert(sorted.begin(), _nbrs.begin(), _nbrs.begin() + pairSize * 2);

    while (true) {
        size_t indPent = 0;
        size_t b = pairSize * (2 + indPent) - 1;
        if (b >= _nbrs.size())
            break;

        bool inserted = false;
        for (size_t i = pairSize - 1; i < sorted.size(); i += pairSize) {
            if (_nbrs[b] < sorted[i]) {
                sorted.insert(sorted.begin() + i - pairSize + 1, _nbrs.begin() + b + 1, _nbrs.begin() + b + pairSize + 1);
                inserted = true;
                break;
            }
        }
        if (!inserted)
            sorted.insert(sorted.end(), _nbrs.begin() + b + 1, _nbrs.begin() + b + pairSize + 1);

        for (size_t i = 0; i < sorted.size(); i++) {
            std::cout << sorted[i] << " ";
        }
        std::cout << std::endl;
        break;

        indPent++;
    }

    // for (size_t i = pairSize - 1; i < _nbrs.size(); i += pairSize) {
    //     uint a = _nbrs[i];
    //     std::cout << "comparing " << _nbrs[b] << " and " << a << std::endl;
    //     if (_nbrs[b] < a) {
    //         _nbrs.insert(_nbrs.begin() + i - pairSize + 1, _nbrs.begin() + b + 1, _nbrs.begin() + b + pairSize + 1);
    //         _nbrs.erase(_nbrs.begin() + b + 1, _nbrs.begin() + b + pairSize + 1);
    //         print(level);
    //     }
    // }
}

void PmergeMe::_splitPairs(uint level) {
    size_t pairSize = _getPairSize(level);
    if (_nbrs.size() / (pairSize / 2) < 2) {
        return;
    }

    // std::cout << "before splitPairs at level " << level << " pairSize: " << pairSize << std::endl;

    for (size_t i = pairSize - 1; i < _nbrs.size(); i += pairSize) {
        uint a = _nbrs[i - pairSize / 2];
        uint b = _nbrs[i];
        // std::cout << "comparing " << a << " and " << b << std::endl;
        if (a > b) {
            _swapRange(i - pairSize / 2, i, pairSize / 2);
            // std::cout << "swapped " << a << " and " << b << " at level " << level << std::endl;
        }
    }
    // std::cout << "after splitPairs at level " << level << std::endl;
    print(level);
    _splitPairs(level + 1);
    _sortLevel(level, pairSize);
    // _insertLast(level, pairSize);
}

void PmergeMe::sort() {
    _splitPairs(1);
    print(1);
}

void PmergeMe::print(uint level) {
    for (uint i = 0; i < _nbrs.size(); i++) {
        std::cout << _nbrs[i] << " ";
        if ((i + 1) % (_getPairSize(level) / 2) == 0) {
            std::cout << "| ";
        }
    }
    std::cout << std::endl;
}
