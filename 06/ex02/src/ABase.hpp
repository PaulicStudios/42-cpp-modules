/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABase.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:23:33 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 00:42:45 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class BaseA;
class BaseB;
class BaseC;

class ABase {
public:
    virtual ~ABase();

    static ABase *generate();
    static void identify(ABase *p);
    static void identify(ABase &p);
};
