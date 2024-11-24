/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:20:41 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/24 12:50:31 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <chrono>

class BitcoinExchange {
	private:
		const std::string _fileName;
		std::map<std::time_point, double> _exchangeRates;

		BitcoinExchange();

		void _loadExchangeRates();
	public:
		BitcoinExchange(std::string fileName);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
};
