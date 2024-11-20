/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:13:21 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 00:20:06 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::Serialize() {}

Serialize::Serialize(Serialize const &) {}

Serialize &Serialize::operator=(Serialize const &) {
    return *this;
}

Serialize::~Serialize() {}

uintptr_t Serialize::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
