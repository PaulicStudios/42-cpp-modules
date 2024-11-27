/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:48:28 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/27 13:24:59 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _exchangeRates(_loadExchangeRates()) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _exchangeRates(src._exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &) {
	return (*this);
}

std::chrono::system_clock::time_point BitcoinExchange::_parseDate(const std::string &date) {
	std::tm tm = {};
	std::stringstream ss(date);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail()) {
		return (std::chrono::system_clock::time_point::min());
	}

	return (std::chrono::system_clock::from_time_t(std::mktime(&tm)));
}

std::map<std::chrono::system_clock::time_point, double> BitcoinExchange::_loadExchangeRates() {
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open()) {
		throw std::runtime_error("Could not open data.csv");
	}

	std::map<std::chrono::system_clock::time_point, double> exchangeRates;
	std::string line;
	while (std::getline(dataFile, line)) {
		std::string date = line.substr(0, line.find(','));
		if (date == "date")
			continue;
		std::string rate = line.substr(line.find(',') + 1);
		std::chrono::system_clock::time_point time = _parseDate(date);

		if (time == std::chrono::system_clock::time_point::min() || date.empty() || rate.empty()) {
			std::cerr << "Error: Invalid date or rate on line: " << line << std::endl;
			continue;
		}
		exchangeRates.insert(std::make_pair(time, std::stod(rate)));
	}

	return (exchangeRates);
}
