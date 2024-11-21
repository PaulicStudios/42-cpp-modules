/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:50:17 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 15:12:30 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>

int main(void)
{
    Array<int> intArray;

    Array<std::string> stringArray(2);
    stringArray[0] = "42";
    stringArray[1] = "Heilbronn";

    std::cout << stringArray[0] << std::endl;
    std::cout << stringArray[1] << std::endl;

    try {
        std::cout << stringArray[2] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Copying stringArray to stringArray2" << std::endl;
    Array<std::string> stringArray2(stringArray);
    std::cout << stringArray2[0] << std::endl;
    std::cout << stringArray2[1] << std::endl;

    std::cout << "Assigning stringArray to stringArray3" << std::endl;
    Array<std::string> stringArray3;
    stringArray3 = stringArray;
    std::cout << stringArray3[0] << std::endl;
    std::cout << stringArray3[1] << std::endl;

    // system("leaks array");
    return 0;
}
