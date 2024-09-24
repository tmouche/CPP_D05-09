/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:25:49 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/24 13:20:41 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.template.hpp"
#include <vector>
#include <iostream>

int	main( void ) {
	std::vector<int>intVector;
	
	for (int idx = 0; idx < 10; idx++)
		intVector.push_back(idx);
	if (easyFind< std::vector<int> >(intVector, 5) == true)
		std::cout << "the searched number is in" << std::endl;
	else
		std::cout << "the searched number is not in" << std::endl;
	return 1;
}
