/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:45:25 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/21 14:01:38 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename V1, typename V2>
void swap(V1 &a, V2 &b) {
    V1 tmp = a;
    a = b;
    b = tmp;
}

template <typename V1, typename V2>
V1 min(V1 a, V2 b) {
    return a < b ? a : b;
}

template <typename V1, typename V2>
V1 max(V1 a, V2 b) {
    return a > b ? a : b;
}
