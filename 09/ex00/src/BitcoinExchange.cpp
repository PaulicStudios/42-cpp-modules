/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:48:28 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/24 13:09:43 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _fileName(""), _exchangeRates(_loadExchangeRates()) {}

BitcoinExchange::BitcoinExchange(std::string fileName) : _fileName(fileName), _exchangeRates(_loadExchangeRates()) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _fileName(src._fileName), _exchangeRates(src._exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
	return (*this);
}

std::map<std::time_t, double> BitcoinExchange::_loadExchangeRates() {
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open()) {
		throw std::runtime_error("Could not open data file");
	}

	std::string line;
	while (std::getline(dataFile, line)) {
		std::string date = line.substr(0, line.find(','));
		if (date == "date")
			continue;
		std::string rate = line.substr(line.find(',') + 1);
		std::time_t time = std::mktime(std::localtime(&date));

		if (time == -1 || date.empty() || rate.empty()) {
			std::cerr << "Error: Invalid date or rate on line: " << line << std::endl;
			continue;
		}
		_exchangeRates.insert(std::make_pair(time, std::stod(rate)));
	}
}
