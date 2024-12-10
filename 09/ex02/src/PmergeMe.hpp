/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:58:37 by pgrossma          #+#    #+#             */
/*   Updated: 2024/12/10 10:37:00 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>

class PmergeMe {
    private:
        std::vector<uint> _nbrs;

        void _splitPairs(uint level);
        void _insertLast(uint pairSize, uint level);
        size_t _getPairSize(uint level);
        void _swapRange(size_t a, size_t b, size_t size);
        void _sortLevel(uint level, uint pairSize);

    public:
        PmergeMe(std::vector<std::string> args);
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        void sort();
        void print(uint level);
};
