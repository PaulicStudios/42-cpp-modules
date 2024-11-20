/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:31:21 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 00:43:07 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABase.hpp"
#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"

#include <random>

ABase::~ABase() = default;

void ABase::identify(ABase *p) {
    std::cout << "ABase *" << p << std::endl;
}

void ABase::identify(ABase &p) {
    std::cout << "ABase &" << &p << std::endl;
}

ABase *ABase::generate() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);
    int random_number = dis(gen);

    switch (random_number) {
        case 0:
            return new BaseA();
        case 1:
            return new BaseB();
        case 2:
            return new BaseC();
    }
    return (nullptr);
}
