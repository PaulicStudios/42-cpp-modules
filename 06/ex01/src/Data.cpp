/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:11:32 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 00:12:05 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _data("42 Heilbronn") {}

Data::Data(Data const &Data) : _data(Data._data) {}

Data &Data::operator=(Data const &Data) {
    this->_data = Data._data;
    return *this;
}

Data::~Data() {}

std::string Data::getData() const {
    return this->_data;
}
