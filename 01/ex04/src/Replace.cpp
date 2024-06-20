/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:50:39 by pgrossma          #+#    #+#             */
/*   Updated: 2024/06/20 17:27:57 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename)
{
	_inFile.open(filename, std::fstream::in);
	if (_inFile.fail())
	{
		std::cerr << "Error: could not open in file" << std::endl;
		exit(1);
	}
	_outFile.open(filename + ".replace", std::fstream::out | std::fstream::trunc);
	if (_outFile.fail())
	{
		std::cerr << "Error: could not open out file" << std::endl;
		exit(1);
	}
}

void Replace::replace(std::string s1, std::string s2)
{
	if (s1.empty())
	{
		std::cerr << "Error: s1 is empty" << std::endl;
		exit(1);
	}
	if (!_inFile.is_open() || !_outFile.is_open())
	{
		std::cerr << "Error: file is not open" << std::endl;
		exit(1);
	}

	std::string line;
	while (std::getline(_inFile, line))
	{
		const char	*find;
		while ((find = std::strstr(line.c_str(), s1.c_str())))
		{
			_outFile << line.substr(0, find - line.c_str()) << s2;
			line = line.substr(find - line.c_str() + s1.length());
		}
		_outFile << line << std::endl;
	}
}

Replace::~Replace()
{
	_inFile.close();
	_outFile.close();
}
