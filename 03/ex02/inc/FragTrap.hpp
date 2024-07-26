/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:41:22 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/26 15:25:58 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);
		FragTrap &operator=(FragTrap const &rhs);
		~FragTrap();

		void	highFiveGuys();
};
