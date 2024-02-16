/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 06:45:17 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/16 07:27:45 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCALAR_
# define _SCALAR_

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter {
public:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    static void convert(const std::string value);
};

#endif
