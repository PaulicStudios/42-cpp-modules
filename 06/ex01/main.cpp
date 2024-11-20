/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:28:56 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 00:19:37 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include "Data.hpp"

#include <iostream>

int main() {
    Data data;
    uintptr_t raw = Serialize::serialize(&data);
    Data *deserialized = Serialize::deserialize(raw);
    std::cout << "Original: " << data.getData() << "(" << &data << ")" << std::endl;
    std::cout << "Deserialized: " << deserialized->getData() << "(" << deserialized << ")" << std::endl;
    return 0;
}
