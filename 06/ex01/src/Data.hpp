/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:09:15 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 00:11:17 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Data {
    private:
        std::string _data;

    public:
        Data();
        Data(Data const &Data);
        Data &operator=(Data const &Data);
        ~Data();

        std::string getData() const;
};
