/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 04:55:08 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/18 05:00:11 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.class.hpp"
#include <iostream>

int	main( void ) {
	Data	test;

	test.x = 1;
	test.y = 2;
	test.z = 3;
	std::cout << "Data test adress: " << &test << std::endl;
	std::cout << "component x: " << test.x << std::endl;
	std::cout << "component y: " << test.y << std::endl;
	std::cout << "component z: " << test.z << std::endl;
	std::cout << "--serialize and deserialize--" << std::endl;
	Serializer::deserialize(Serializer::serialize(&test));
	std::cout << "Data test adress: " << &test << std::endl;
	std::cout << "component x: " << test.x << std::endl;
	std::cout << "component y: " << test.y << std::endl;
	std::cout << "component z: " << test.z << std::endl;
}
