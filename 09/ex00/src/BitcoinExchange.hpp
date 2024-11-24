/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:20:41 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/24 13:10:07 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <ctime>
#include <fstream>

class BitcoinExchange {
	private:
		const std::string _fileName;
		const std::map<std::time_t, double> _exchangeRates;

		BitcoinExchange();

		std::map<std::time_t, double> _loadExchangeRates();
	public:
		BitcoinExchange(std::string fileName);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
};
