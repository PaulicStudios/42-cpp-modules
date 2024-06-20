/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:47:52 by pgrossma          #+#    #+#             */
/*   Updated: 2024/06/20 16:47:54 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int const	n = 10;
	Zombie*		zombie = zombieHorde(n, "Zombie Heap");

	for (int i = 0; i < n; i++)
		zombie[i].announce();

	delete[] zombie;

	// system("leaks zombieHorde");
}
