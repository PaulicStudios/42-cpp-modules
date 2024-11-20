/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:31:21 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 00:55:17 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABase.hpp"
#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"

#include <random>

ABase::~ABase() = default;

void ABase::identify(ABase *p) {
    if (dynamic_cast<BaseA *>(p))
        std::cout << "BaseA" << std::endl;
    else if (dynamic_cast<BaseB *>(p))
        std::cout << "BaseB" << std::endl;
    else if (dynamic_cast<BaseC *>(p))
        std::cout << "BaseC" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void ABase::identify(ABase &p) {
    try {
        (void) dynamic_cast<BaseA &>(p);
        std::cout << "BaseA" << std::endl;
    } catch (std::exception &e) {
        try {
            dynamic_cast<BaseB &>(p);
            std::cout << "BaseB" << std::endl;
        } catch (std::exception &e) {
            try {
                dynamic_cast<BaseC &>(p);
                std::cout << "BaseC" << std::endl;
            } catch (std::exception &e) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

ABase *ABase::generate() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);
    int random_number = dis(gen);

    switch (random_number) {
        case 0:
            std::cout << "Generating BaseA" << std::endl;
            return new BaseA();
        case 1:
            std::cout << "Generating BaseB" << std::endl;
            return new BaseB();
        case 2:
            std::cout << "Generating BaseC" << std::endl;
            return new BaseC();
    }
    return (nullptr);
}
