/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:28:56 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 00:56:36 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABase.hpp"

#include <iostream>

int main() {
    ABase *base = ABase::generate();
    ABase::identify(base);
    ABase::identify(*base);
    ABase::identify(nullptr);
    delete base;
}
