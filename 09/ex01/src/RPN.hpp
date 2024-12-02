/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:08:59 by pgrossma          #+#    #+#             */
/*   Updated: 2024/12/02 15:13:30 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class RPN {
	private:
		std::string _input;
		std::stack<int> _stack;

		RPN();
	public:
		RPN(std::string input);
		~RPN();
		RPN(const RPN &src);
		RPN	&operator=(const RPN &src);
		int getResult() const;
}
