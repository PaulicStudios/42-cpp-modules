/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:11:30 by pgrossma          #+#    #+#             */
/*   Updated: 2025/01/10 17:32:57 by pgrossma         ###   ########.fr       */
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

void PmergeMe::sort() {
    _removeDuplicates();
    _sortPairs(1);
    print(1);
}

void PmergeMe::_removeDuplicates() {
    for (std::vector<uint>::iterator it = _nbrs.begin(); it != _nbrs.end(); ++it) {
        if (std::find(_nbrs.begin(), it, *it) != it) {
            _nbrs.erase(it);
            it = _nbrs.begin();
        }
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

    std::vector<uint> pend;

    for (uint i = pairSize - 1; i < _nbrs.size(); i += pairSize) {
        uint pair1 = i + level - 1;
        uint pair2 = i + pairSize - 1;
        if (pair2 >= _nbrs.size()) {
            break;
        }
        pend.insert(pend.end(), _nbrs.begin() + pair1 + 2 - level, _nbrs.begin() + pair1 + 2);
        _nbrs.erase(_nbrs.begin() + pair1 + 2 - level, _nbrs.begin() + pair1 + 2);
        i -= level;
    }

    std::vector<uint> insertionOrder;

    uint indJac = 2;
    while (pend.size() / level >= _jacobsthal(indJac)) {
        uint rangeStart = _jacobsthal(indJac - 1);
        uint rangeEnd = _jacobsthal(indJac);
        for (uint i = rangeEnd; i > rangeStart; i--) {
            insertionOrder.push_back(i);
        }
        indJac++;
    }

    // Insert pend into _nbrs in insertionOrder
    for (uint i = 0; i < insertionOrder.size(); i++) {
        uint pendInd = (insertionOrder[i] - 1) * level - 1;
        for (uint j = level - 1; j < _nbrs.size(); j += level) {
            if (pend[pendInd] < _nbrs[j]) {
                _nbrs.insert(_nbrs.begin() + j - level + 1, pend.begin() + pendInd - level + 1, pend.begin() + pendInd + 1);
                break;
            }
        }
    }

    // Remove already inserted pend from pend
    std::sort(insertionOrder.begin(), insertionOrder.end(), std::greater<uint>());
    for (uint i = 0; i < insertionOrder.size(); i++) {
        uint pendInd = (insertionOrder[i] - 1) * level - 1;
        pend.erase(pend.begin() + pendInd - level + 1, pend.begin() + pendInd + 1);
    }

    // Insert remaining pend into _nbrs
    for (uint i = level - 1; i < pend.size(); i += level) {
        bool inserted = false;
        for (uint j = level - 1; j < _nbrs.size(); j += level) {
            if (pend[i] < _nbrs[j]) {
                _nbrs.insert(_nbrs.begin() + j - level + 1, pend.begin() + i - level + 1, pend.begin() + i + 1);
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            _nbrs.insert(_nbrs.end() - _nbrs.size() % level, pend.begin() + i - level + 1, pend.begin() + i + 1);
        }
    }

    // Insert odd numbers into _nbrs
    uint oddEnd = _nbrs.size() % level;
    bool odd = (_nbrs.size() / level) % 2;
    if (odd) {
        uint oddPair = _nbrs.size() - oddEnd - 1;
        for (uint j = level - 1; j < _nbrs.size(); j += level) {
            if (_nbrs[oddPair] < _nbrs[j]) {
                std::vector<uint> oddPairVec;
                oddPairVec.insert(oddPairVec.end(), _nbrs.begin() + oddPair - level + 1, _nbrs.begin() + oddPair + 1);
                _nbrs.insert(_nbrs.begin() + j - level + 1, oddPairVec.begin(), oddPairVec.end());
                _nbrs.erase(_nbrs.begin() + oddPair + 1, _nbrs.begin() + oddPair + 1 + level);
                break;
            }
        }
    }
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

uint PmergeMe::_jacobsthal(uint n) {
    return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

void PmergeMe::_swapPairs(uint pair1, uint pair2, uint level) {
    for (uint i = 0; i < level; i++) {
        std::swap(_nbrs[pair1 - (level - 1) + i], _nbrs[pair2 - (level - 1) + i]);
    }
}
