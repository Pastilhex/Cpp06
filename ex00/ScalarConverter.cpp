/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 06:45:34 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/15 19:41:10 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& original) {
	*this = original;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) {
	*this = obj;
	return *this;
}

void ScalarConverter::convert(const std::string value)
{
	bool	charType = true, intType = true, floatType = true, doubleType = true;
	double	finalValue = 0.0;
	int		charValue = 0;
	int		intValue = 0;
	float	floatValue = 0.0f;
	double	doubleValue = 0.0;

	for (size_t i = 0; i < value.size(); i++)
	{
		switch (value[i])
		{
		case '-':
			charType = false;
			finalValue *= -1;
			break;

		case '.':
			charType = false;
			intType = false;
			finalValue += static_cast<int>(value[i]);
			break;

		case 'f':
			charType = false;
			intType = false;
			doubleType = false;
			finalValue += static_cast<int>(value[i]);
			break;

		default:
			finalValue += static_cast<int>(value[i]);
		}
	}

	if (charType)
		charValue = static_cast<int>(finalValue);
	if (intType)
		intValue = atoi(value.c_str());
	if (floatType)
		floatValue = static_cast<float>(atof(value.c_str()));
	if (doubleType)
		doubleValue = static_cast<double>(atof(value.c_str()));

	std::cout << "char: " << charValue << " " << static_cast<int>(finalValue) << std::endl;
	std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << floatValue << std::endl;
	std::cout << "double: " << doubleValue << std::endl;
}
