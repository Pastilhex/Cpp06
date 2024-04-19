/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 06:45:17 by ialves-m          #+#    #+#             */
/*   Updated: 2024/04/19 11:51:04 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCALAR_
#define _SCALAR_

#include <iostream>
#include <string>
#include <limits>
#include <cmath>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);
	~ScalarConverter();

public:
	static void convert(const std::string value);
};

#endif
