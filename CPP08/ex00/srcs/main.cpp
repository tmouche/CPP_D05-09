/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:25:49 by tmouche           #+#    #+#             */
/*   Updated: 2025/03/23 16:07:10 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.template.hpp"
#include <vector>
#include <list>
#include <iostream>

int	main( void ) {
	std::vector<int>intVector;
	std::list<int>intList;
	int				searched;

	for (int idx = 0; idx < 10; idx++) {
		intVector.push_back(idx);
		intList.push_back(idx);
	}
	searched = 5;
	if (easyFind< std::vector<int> >(intVector, searched) == true)
		std::cout << "the searched " << searched << " number is in the vector" << std::endl;
	else
		std::cout << "the searched " << searched << " number is not in the vector" << std::endl;
	if (easyFind< std::list<int> >(intList, searched) == true)
		std::cout << "the searched " << searched << " number is in the vector" << std::endl;
	else
		std::cout << "the searched " << searched << " number is not in the vector" << std::endl;
	searched = 12;
	if (easyFind< std::vector<int> >(intVector, searched) == true)
		std::cout << "the searched " << searched << " number is in the vector" << std::endl;
	else
		std::cout << "the searched " << searched << " number is not in the vector" << std::endl;
	if (easyFind< std::list<int> >(intList, searched) == true)
		std::cout << "the searched " << searched << " number is in the vector" << std::endl;
	else
		std::cout << "the searched " << searched << " number is not in the vector" << std::endl;
	return 1;
}
