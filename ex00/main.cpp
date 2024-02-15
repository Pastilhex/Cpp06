/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 06:44:23 by ialves-m          #+#    #+#             */
/*   Updated: 2024/02/15 14:22:57 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{

    if (argc == 2)
    {
        std::string tmp = argv[1];
        ScalarConverter::convert(argv[1]);
    }
    return 0;    
}
