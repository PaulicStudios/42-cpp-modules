/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:48:28 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/24 12:50:01 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _fileName("") {
	this->_exchangeRates = std::map<std::time_point, double>();
}

BitcoinExchange::BitcoinExchange(std::string fileName) : _fileName(fileName) {
	this->_exchangeRates = std::map<std::time_point, double>();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	this->_exchangeRates = src._exchangeRates;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
	this->_exchangeRates = src._exchangeRates;
	return (*this);
}
