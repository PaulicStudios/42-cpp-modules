/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:10:38 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/25 19:16:27 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap	scavTrap1("ST 1");
	ScavTrap	scavTrap2;

	scavTrap2 = ScavTrap("ST 2");

	scavTrap1.attack("target");
	scavTrap1.guardGate();
	scavTrap1.guardGate();
	scavTrap1.guardGate();

	return 0;
}
