/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:58:37 by pgrossma          #+#    #+#             */
/*   Updated: 2025/01/10 18:14:06 by pgrossma         ###   ########.fr       */
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

        void _removeDuplicates();
        void _sortPairs(uint level);
        void _swapPairs(uint pair1, uint pair2, uint level);
        uint _jacobsthal(uint n);
        std::vector<uint> _getInsertionOrder(std::vector<uint> &pend, uint level);
        std::vector<uint> _fillPend(uint level, uint pairSize);
        void _insertPendUsingInsertionOrder(std::vector<uint> &pend, std::vector<uint> &insertionOrder, uint level);
        void _insertRemainingPend(std::vector<uint> &pend, uint level);
        void _insertOddNumbers(uint level);

    public:
        PmergeMe(std::vector<std::string> args);
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        std::vector<uint> &sort();
};
