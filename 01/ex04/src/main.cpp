/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:48:21 by pgrossma          #+#    #+#             */
/*   Updated: 2024/06/20 17:29:24 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <fileName> <s1> <s2>" << std::endl;
		return (1);
	}
	Replace	replace(argv[1]);
	replace.replace(argv[2], argv[3]);

	// system("leaks replace");
}
