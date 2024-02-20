/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:06:52 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/20 14:44:42 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base* generate(void);
static void identify(Base* p);
static void identify(Base& p);

int main(void) {
	Base* obj = generate();

	identify(obj);
	identify(*obj);

	return 0;
}

Base* generate(void) 
{
	std::srand(std::time(0));

	int random = rand();
	int randNumber = (random % 3 + 1);
	Base* obj;
	if (randNumber == 1)
 		obj = new A();
	else if (randNumber == 2)
		obj = new B();
	else if (randNumber == 3)
		obj = new C();
	return obj;
}

void identify(Base* p) 
{
	if (0 != dynamic_cast<A*>(p))
		std::cout << "Type A" << std::endl;
	else if (0 != dynamic_cast<B*>(p))
		std::cout << "Type B" << std::endl;
	else if (0 != dynamic_cast<C*>(p))
		std::cout << "Type C" << std::endl;
	else
		std::cout << "No Type" << std::endl;
}

void identify(Base& p) 
{
	if (0 != dynamic_cast<A*>(&p))
		std::cout << "Type A" << std::endl;
	else if (0 != dynamic_cast<B*>(&p))
		std::cout << "Type B" << std::endl;
	else if (0 != dynamic_cast<C*>(&p))
		std::cout << "Type C" << std::endl;
	else
		std::cout << "No Type" << std::endl;
}
