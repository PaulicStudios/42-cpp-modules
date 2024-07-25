/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:10:38 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/25 17:38:38 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	clapTrap("CT 1");
	ClapTrap	clapTrap2(clapTrap);
	ClapTrap	clapTrap3;

	clapTrap3 = clapTrap2;
	clapTrap.attack("target");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);

	return 0;
}
