/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:58:36 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/26 17:02:27 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Brain {
	private:
		std::string	*_ideas;
	public:
		Brain();
		Brain(Brain const &Brain);
		Brain& operator=(Brain const &Brain);
		~Brain();
};
