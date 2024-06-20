/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:48:14 by pgrossma          #+#    #+#             */
/*   Updated: 2024/06/20 18:16:23 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

class Replace {
	private:
		std::ifstream	_inFile;
		std::ofstream	_outFile;
	public:
		Replace(std::string fileName);
		~Replace();
		void	replace(std::string s1, std::string s2);
};
