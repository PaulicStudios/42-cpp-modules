/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:50:17 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/23 15:21:46 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
    {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    }
    std::cout << "----------------------------------------" << std::endl;
    {
        MutantStack<std::string> mstack;
        mstack.push("42");
        mstack.push("Heilbronn");

        MutantStack<std::string>::iterator it = std::find(mstack.begin(), mstack.end(), "42");
        std::cout << *it << std::endl;
    }

    return (0);
}
