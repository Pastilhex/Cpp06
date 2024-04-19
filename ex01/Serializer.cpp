/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:09:07 by ialves-m          #+#    #+#             */
/*   Updated: 2024/04/19 11:36:24 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){};

Serializer::~Serializer(){};

Serializer::Serializer(const Serializer &original)
{
	*this = original;
}

Serializer &Serializer::operator=(const Serializer &obj)
{
	if (this != &obj)
		*this = obj;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
