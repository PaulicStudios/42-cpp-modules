/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:58:37 by pgrossma          #+#    #+#             */
/*   Updated: 2025/01/11 12:23:19 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>

template <typename Container>
class PmergeMe {
    private:
        Container _nbrs;

        void _removeDuplicates();
        void _sortPairs(uint level);
        void _swapPairs(typename Container::iterator pair1, typename Container::iterator pair2, uint level);
        uint _jacobsthal(uint n);
        Container _getInsertionOrder(Container &pend, uint level);
        Container _fillPend(uint level, uint pairSize);
        void _insertPendUsingInsertionOrder(Container &pend, Container &insertionOrder, uint level);
        void _insertRemainingPend(Container &pend, uint level);
        void _insertOddNumbers(uint level);

    public:
        PmergeMe(std::vector<std::string> args);
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        Container &sort();
};

template <typename Container>
PmergeMe<Container>::PmergeMe(std::vector<std::string> args) {
    for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); std::advance(it, 1)) {
        long nbr = std::stol(*it);
        if (nbr < 0) {
            throw std::runtime_error("Negative number");
        } else if (nbr > std::numeric_limits<uint>::max()) {
            throw std::runtime_error("Number too large");
        }
        _nbrs.push_back(static_cast<uint>(nbr));
    }
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &src) {
    *this = src;
}

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe<Container> &src) {
    if (this != &src) {
        this->_nbrs = src._nbrs;
    }
    return *this;
}

template <typename Container>
Container &PmergeMe<Container>::sort() {
    _removeDuplicates();
    _sortPairs(1);
    return _nbrs;
}

template <typename Container>
void PmergeMe<Container>::_removeDuplicates() {
    for (typename Container::iterator it = _nbrs.begin(); it != _nbrs.end(); std::advance(it, 1)) {
        if (std::find(_nbrs.begin(), it, *it) != it) {
            _nbrs.erase(it);
            it = _nbrs.begin();
        }
    }
}

template <typename Container>
void PmergeMe<Container>::_sortPairs(uint level) {
    if (_nbrs.size() / level < 2) {
        return;
    }

    uint pairSize = level * 2;
    for (typename Container::iterator it = _nbrs.begin(); it != std::prev(_nbrs.end(), _nbrs.size() % pairSize); std::advance(it, pairSize)) {
        typename Container::iterator pair1 = std::next(it, level - 1);
        typename Container::iterator pair2 = std::next(it, pairSize - 1);
        if (*pair1 > *pair2) {
            _swapPairs(pair1, pair2, level);
        }
    }
    _sortPairs(level * 2);

    // Fill pend from _nbrs
    Container pend = _fillPend(level, pairSize);

    // Get insertion order for pend using jacobsthal numbers
    Container insertionOrder = _getInsertionOrder(pend, level);

    // Insert pend into _nbrs in insertionOrder and remove from pend
    _insertPendUsingInsertionOrder(pend, insertionOrder, level);

    if (pend.size() > 0) {
        // Insert remaining pend into _nbrs
        _insertRemainingPend(pend, level);
    }

    // Insert odd numbers into _nbrs
    _insertOddNumbers(level);
}

template <typename Container>
Container PmergeMe<Container>::_fillPend(uint level, uint pairSize) {
    Container pend;
    for (typename Container::iterator it = std::next(_nbrs.begin(), pairSize - 1); it != std::prev(_nbrs.end(), _nbrs.size() % pairSize); std::advance(it, pairSize)) {
        if (std::next(it, pairSize - 1) >= _nbrs.end()) {
            break;
        }

        typename Container::iterator pair1 = std::next(it, level - 1);
        typename Container::iterator start;

        int startInd = 2 - level;
        if (startInd < 0) {
            startInd = -startInd;
            start = std::prev(pair1, startInd);
        } else {
            start = std::next(pair1, startInd);
        }
        
        pend.insert(pend.end(), start, std::next(pair1, 2));
        _nbrs.erase(start, std::next(pair1, 2));
        it = std::prev(it, level);
    }

    return pend;
}

template <typename Container>
Container PmergeMe<Container>::_getInsertionOrder(Container &pend, uint level) {
    Container insertionOrder;
    uint indJac = 2;

    while (pend.size() / level >= _jacobsthal(indJac)) {
        uint rangeStart = _jacobsthal(indJac - 1);
        uint rangeEnd = _jacobsthal(indJac);
        for (uint i = rangeEnd; i > rangeStart; i--) {
            insertionOrder.push_back(i);
        }
        indJac++;
    }

    return insertionOrder;
}

template <typename Container>
void PmergeMe<Container>::_insertPendUsingInsertionOrder(Container &pend, Container &insertionOrder, uint level) {
    for (typename Container::iterator it = insertionOrder.begin(); it != insertionOrder.end(); std::advance(it, 1)) {
        typename Container::iterator pendInd = std::next(pend.begin(), (*it - 1) * level - 1);
        for (typename Container::iterator j = std::next(_nbrs.begin(), level - 1); j != std::prev(_nbrs.end(), _nbrs.size() % level); std::advance(j, level)) {
            if (*pendInd < *j) {
                _nbrs.insert(std::prev(j, level - 1), std::prev(pendInd, level - 1), std::next(pendInd, 1));
                break;
            }
        }
    }

    // Remove already inserted pend from pend
    std::sort(insertionOrder.begin(), insertionOrder.end(), std::greater<uint>());
    for (typename Container::iterator it = insertionOrder.begin(); it != insertionOrder.end(); std::advance(it, 1)) {
        typename Container::iterator pendInd = std::next(pend.begin(), (*it - 1) * level - 1);
        pend.erase(std::prev(pendInd, level - 1), std::next(pendInd, 1));
    }
}

template <typename Container>
void PmergeMe<Container>::_insertRemainingPend(Container &pend, uint level) {
    for (typename Container::iterator it = std::next(pend.begin(), level - 1); it < pend.end(); std::advance(it, level)) {
        bool inserted = false;
        for (typename Container::iterator j = std::next(_nbrs.begin(), level - 1); j != std::prev(_nbrs.end(), _nbrs.size() % level); std::advance(j, level)) {
            if (*it < *j) {
                _nbrs.insert(std::prev(j, level - 1), std::prev(it, level - 1), std::next(it, 1));
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            _nbrs.insert(std::prev(_nbrs.end(), _nbrs.size() % level), std::prev(it, level - 1), std::next(it, 1));
        }
    }
}

template <typename Container>
void PmergeMe<Container>::_insertOddNumbers(uint level) {
    bool odd = (_nbrs.size() / level) % 2;
    if (odd) {
        typename Container::iterator oddPair = std::prev(_nbrs.end(), _nbrs.size() % level + 1);
        for (typename Container::iterator it = std::next(_nbrs.begin(), level - 1); it < _nbrs.end(); std::advance(it, level)) {
            if (*oddPair < *it) {
                Container oddPairVec;
                oddPairVec.insert(oddPairVec.end(), std::prev(oddPair, level - 1), std::next(oddPair, 1));
                _nbrs.insert(std::prev(it, level - 1), oddPairVec.begin(), oddPairVec.end());
                _nbrs.erase(std::prev(_nbrs.end(), _nbrs.size() % level + level), std::prev(_nbrs.end(), _nbrs.size() % level));
                break;
            }
        }
    }
}

template <typename Container>
uint PmergeMe<Container>::_jacobsthal(uint n) {
    return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

template <typename Container>
void PmergeMe<Container>::_swapPairs(typename Container::iterator pair1, typename Container::iterator pair2, uint level) {
    for (uint i = 0; i < level; i++) {
        std::swap(*(std::prev(pair1, (level - 1) - i)), *(std::prev(pair2, (level - 1) - i)));
    }
}
