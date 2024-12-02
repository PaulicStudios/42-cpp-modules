/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:13:39 by pgrossma          #+#    #+#             */
/*   Updated: 2024/12/02 16:32:11 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string input) : _input(input) {}

RPN::~RPN() {}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN	&RPN::operator=(const RPN &src) {
	this->_input = src._input;
	this->_stack = src._stack;
	return (*this);
}

int RPN::_calcResult(int a, int b, char op) {
	switch (op)
	{
	case '+':
		return (a + b);
	case '-':
		return (b - a);
	case '*':
		return (a * b);
	case '/':
		if (a == 0) {
			throw std::runtime_error("Division by zero");
		}
		return (b / a);
	default:
		throw std::runtime_error("Operant '" + std::to_string(op) + "' not supported");
	}
}

void RPN::_handleToken(std::string token) {
	if (token.empty()) {
		return;
	}

	if (token.size() > 1) {
		throw std::runtime_error("Invalid token: '" + token + "' is too long");
	}

	if (token == "+" || token == "-" || token == "*" || token == "/") {
		if (_stack.size() < 2) {
			throw std::runtime_error("Not enough numbers on the stack");
		}

		int a = _stack.top();
		_stack.pop();
		int b = _stack.top();
		_stack.pop();

		_stack.push(_calcResult(a, b, token[0]));
	} else {
		try {
			_stack.push(std::stoi(token));
		} catch (const std::exception &e) {
			throw std::runtime_error("Invalid token: '" + token + "': " + e.what());
		}
	}
}

int RPN::getResult() {
	std::istringstream iss(this->_input);

	while (!iss.fail()) {
		std::string token;
		iss >> token;
		_handleToken(token);
	}

	if (_stack.size() != 1) {
		throw std::runtime_error("Invalid input: " + std::to_string(_stack.size()) + " numbers left on the stack");
	}

	return (_stack.top());
}
