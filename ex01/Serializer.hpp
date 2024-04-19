/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:09:17 by ialves-m          #+#    #+#             */
/*   Updated: 2024/04/19 11:51:15 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SERIAlIZER_
#define _SERIAlIZER_

#include <iostream>
#include <stdint.h>
#include <string>

typedef struct Data
{
	std::string strValue;
	int intValue;
	bool boolValue;
	double doubleValue;
} Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &);
	Serializer &operator=(const Serializer &);
	~Serializer();

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
