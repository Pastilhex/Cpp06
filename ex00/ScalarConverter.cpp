/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 06:45:34 by ialves-m          #+#    #+#             */
/*   Updated: 2024/04/19 11:27:55 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &original)
{
	*this = original;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	*this = obj;
	return *this;
}

void ScalarConverter::convert(const std::string value)
{
	bool intType = true, errorFlag = false, hifenFlag = false, dotFlag = false, fFlag = false;
	char charValue = 0;
	int intValue = 0;
	float floatValue = 0.0f;
	long double finalValue = 0.0, doubleValue = 0.0, fractionalMultiplier = 0.1;
	if (value == "-inff" || value == "-inf")
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: Overload" << std::endl;
		std::cout << "float: " << -std::numeric_limits<double>::infinity() << "f" << std::endl;
		std::cout << "double: " << -std::numeric_limits<double>::infinity() << std::endl;
	}
	else if (value == "+inff" || value == "+inf")
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: Overload" << std::endl;
		std::cout << "float: +" << std::numeric_limits<double>::infinity() << "f" << std::endl;
		std::cout << "double: +" << std::numeric_limits<double>::infinity() << std::endl;
	}
	else if (value == "nan")
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		for (size_t i = 0; i < value.size(); i++)
		{
			if (!(value[i] >= '0' && value[i] <= '9'))
			{
				if (errorFlag == false)
					errorFlag = true;
				else
					break;
			}
			switch (value[i])
			{
			case '-':
				errorFlag = (hifenFlag == true) ? true : false;
				hifenFlag = true;
				break;
			case '.':
				intType = false;
				errorFlag = (dotFlag == true) ? true : false;
				dotFlag = true;
				break;
			case 'f':
				intType = false;
				errorFlag = (fFlag == true) ? true : false;
				fFlag = true;
				break;
			default:
				if (value[i] >= '0' && value[i] <= '9')
				{
					if (intType == false)
					{
						finalValue += (value[i] - '0') * fractionalMultiplier;
						fractionalMultiplier *= 0.1;
					}
					else
						finalValue = (finalValue * 10) + (value[i] - '0');
				}
				else if (value[i] >= 32 && value[i] <= 126)
					finalValue += value[i];
				else
					errorFlag = true;
			}
		}
		if (errorFlag == false)
		{
			if (hifenFlag)
				finalValue *= -1;
			charValue = static_cast<char>(finalValue);
			intValue = static_cast<int>(finalValue);
			floatValue = static_cast<float>(finalValue);
			doubleValue = static_cast<double>(finalValue);
			if (charValue >= 32 && charValue <= 126)
				std::cout << "char: '" << charValue << "'" << std::endl;
			else if (charValue < 32 || charValue > 126)
				std::cout << "char: Non displayable" << std::endl;

			if (finalValue >= std::numeric_limits<int>::min() && finalValue <= std::numeric_limits<int>::max())
				std::cout << "int: " << intValue << std::endl;
			else
				std::cout << "int: Overload" << std::endl;

			if (floatValue >= -std::numeric_limits<float>::max() && floatValue <= std::numeric_limits<float>::max())
				std::cout << "float: " << floatValue << ((intType) ? ".0f" : "f") << std::endl;
			else
				std::cout << "float: Overload" << std::endl;

			if (finalValue >= -std::numeric_limits<double>::max() && finalValue <= std::numeric_limits<double>::max())
				std::cout << "double: " << doubleValue << ((intType) ? ".0" : "") << std::endl;
			else
				std::cout << "double: Overload" << std::endl;
		}
		else
			std::cout << "INVALID INPUT" << std::endl;
	}
}
