/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:08:59 by pgrossma          #+#    #+#             */
/*   Updated: 2024/12/02 16:31:16 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>

class RPN {
	private:
		std::string _input;
		std::stack<int> _stack;

		RPN();
		int _calcResult(int a, int b, char op);
		void _handleToken(std::string token);

	public:
		RPN(std::string input);
		~RPN();
		RPN(const RPN &src);
		RPN	&operator=(const RPN &src);
		int getResult();
};
