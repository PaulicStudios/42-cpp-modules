/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:58:36 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/29 11:16:49 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain {
	private:
		std::string	_ideas[100];
	public:
		Brain();
		Brain(Brain const &Brain);
		Brain&	operator=(Brain const &Brain);
		virtual	~Brain();
};
