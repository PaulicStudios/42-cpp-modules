/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:48:21 by pgrossma          #+#    #+#             */
/*   Updated: 2024/06/20 18:06:43 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./replace <DEBUG|INFO|WARNING|ERROR>" << std::endl;
		return (1);
	}

	Harl().complain(argv[1]);

	// system("leaks replace");
}
