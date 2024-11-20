/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:05:51 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 00:10:08 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "Data.hpp"

class Serialize {
    private:
        Serialize();
        Serialize(Serialize const &Serialize);
        Serialize &operator=(Serialize const &Serialize);
        ~Serialize();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
