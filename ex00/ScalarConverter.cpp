/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 06:45:34 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/15 14:23:21 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& original) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) {
	return *this;
}

void ScalarConverter::convert(const std::string value)
{
    char charValue;
    int intValue = 0;
    float floatValue = 0.0f;
    double doubleValue = 0.0;
    charValue = atoi(value);
    intValue = atoi(value);
    floatValue = atof(value);
    doubleValue = static_cast<double>(floatValue);
    std::cout << "char: " << charValue << std::endl;
    std::cout << "int: " << intValue << std::endl;
    std::cout << "float: " << floatValue << std::endl;
    std::cout << "double: " << doubleValue << std::endl;
}
