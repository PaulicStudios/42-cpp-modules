/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:20:41 by pgrossma          #+#    #+#             */
/*   Updated: 2025/01/11 13:52:47 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

class BitcoinExchange {
	private:
		const std::map<std::chrono::system_clock::time_point, double> _exchangeRates;

		std::map<std::chrono::system_clock::time_point, double> _loadExchangeRates();
		std::chrono::system_clock::time_point _parseDate(const std::string &date);
		double _calcRate(const std::chrono::system_clock::time_point &date, double value);
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		void lookUpValuesFromFile(const std::string &filename);
};
