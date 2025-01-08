/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:58:37 by pgrossma          #+#    #+#             */
/*   Updated: 2025/01/08 17:15:29 by pgrossma         ###   ########.fr       */
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

        void _sortPairs(uint level);
        void _swapPairs(uint pair1, uint pair2, uint level);

    public:
        PmergeMe(std::vector<std::string> args);
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        void sort();
        void print(uint level);
};
