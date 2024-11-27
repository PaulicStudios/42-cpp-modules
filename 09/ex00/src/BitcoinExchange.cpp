/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:48:28 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/27 17:26:17 by pgrossma         ###   ########.fr       */
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
		std::string dateStr = line.substr(0, line.find(','));
		if (dateStr == "date")
			continue;
		std::string rateStr = line.substr(line.find(',') + 1);
		std::chrono::system_clock::time_point time = _parseDate(dateStr);

		if (time == std::chrono::system_clock::time_point::min() || dateStr.empty() || rateStr.empty()) {
			std::cerr << "Error: Invalid date or rate on line: " << line << std::endl;
			continue;
		}

		double value;
		try {
			value = std::stod(rateStr);
		} catch (const std::exception &e) {
			std::cerr << "Error: Invalid rate on line: " << line << std::endl;
			continue;
		}
		if (value < 0) {
			std::cerr << "Error: Negative value on line: " << line << std::endl;
			continue;
		}

		exchangeRates.insert(std::make_pair(time, value));
	}

	return (exchangeRates);
}

double BitcoinExchange::_calcRate(const std::chrono::system_clock::time_point &date, double value) {
	auto it = _exchangeRates.lower_bound(date);
	if (it == _exchangeRates.end() || it->first != date) {
		--it;
	}
	return (it->second * value);
}

void BitcoinExchange::lookUpValuesFromFile(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file");
	}

	std::string line;
	while (std::getline(file, line)) {
		std::string dateStr = line.substr(0, line.find('|'));
		if (dateStr == "date")
			continue;
		std::string valueStr = line.substr(line.find('|') + 1);

		std::chrono::system_clock::time_point time = _parseDate(dateStr);
		if (time == std::chrono::system_clock::time_point::min() || dateStr.empty() || valueStr.empty()) {
			std::cerr << "Error: Invalid date or rate on line: " << line << std::endl;
			continue;
		}

		double value;
		try {
			value = std::stod(valueStr);
		} catch (const std::exception &e) {
			std::cerr << "Error: Invalid rate on line: " << line << std::endl;
			continue;
		}
		if (value < 0) {
			std::cerr << "Error: Negative value on line: " << line << std::endl;
			continue;
		}
		if (value > std::numeric_limits<int>::max()) {
			std::cerr << "Error: Value is too large on line: " << line << std::endl;
			continue;
		}

		double rate = _calcRate(time, value);
		std::cout << dateStr << " => " << value << " = " << rate << std::endl;
	}
}
