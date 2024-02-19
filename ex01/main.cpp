/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:16:13 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/19 16:04:03 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data* data = new Data;
	
	data->strValue = "42 Porto";
	data->intValue = 42;
	data->boolValue = true;
	data->doubleValue = 42.42;

	uintptr_t raw = Serializer::serialize(data);
	
	Data* data2 = Serializer::deserialize(raw);

	std::cout << "Before serialization" << std::endl;
	std::cout << data->strValue << std::endl;
	std::cout << data->intValue << std::endl;
	std::cout << data->boolValue << std::endl;
	std::cout << data->doubleValue << std::endl;

	std::cout << std::endl;
	std::cout << "After serialization" << std::endl;
	std::cout << data2->strValue << std::endl;
	std::cout << data2->intValue << std::endl;
	std::cout << data2->boolValue << std::endl;
	std::cout << data2->doubleValue << std::endl;

	delete data;
	return 0;
}
