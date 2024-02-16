/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 06:45:34 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/16 07:33:49 by ialves-m         ###   ########.fr       */
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
	//charType = true, intType = true, floatType = true, doubleType = true,
	bool	intType = true, errorFlag = false, hifenFlag = false, dotFlag = false, fFlag = false;
	char	charValue = 0;
	int		intValue = 0;
	float	floatValue = 0.0f;
	double	finalValue = 0.0, doubleValue = 0.0, fractionalMultiplier = 0.1;
	
	for (size_t i = 0; i < value.size(); i++)
	{
		switch (value[i])
		{
		case '-':
			finalValue *= -1;
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

	charValue = static_cast<char>(finalValue);
	intValue = static_cast<int>(finalValue);
	floatValue = static_cast<float>(finalValue);
	doubleValue = static_cast<double>(finalValue);

	if (errorFlag == false)
	{
		if (charValue >= 32 && charValue <= 126)
			std::cout << "char: '" << charValue << "'" << std::endl;
		else if (charValue < 32 && charValue > 126)
			std::cout << "char: Non displayable" << std::endl;
			
		std::cout << "int: " << intValue << std::endl;
		std::cout << "float: " << floatValue << ((intType) ? ".0f" : "f") << std::endl;
		std::cout << "double: " << doubleValue << ((intType) ? ".0" : "") << std::endl;
	}
}
