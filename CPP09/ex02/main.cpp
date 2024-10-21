/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:06:37 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/21 20:59:45 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.class.hpp"
#include <iostream>

int	main( void ) {
	int			array[6] = {6, 10, 3, 8, 2, 7};
	PmergeMe	test(array, 6);
	
	test.doubleSortMyNumber();

// 	std::vector<int>test;
// 	std::vector<int>test2;
// 	std::vector<std::vector<int>*>testCont;

// 	test.push_back(1);
// 	test2.push_back(2);
// 	testCont.push_back(&test);
// 	testCont.push_back(&test2);
// 	for (int idx = 0; idx < testCont.size(); idx++)
// 		std::cout << testCont[idx]->back();
// 	std::cout << std::endl << "-------------------" << std::endl;
// 	testCont.push_back(testCont.front());
// 	testCont.erase(testCont.begin());
// 	for (int idx = 0; idx < testCont.size(); idx++)
// 		std::cout << testCont[idx]->back();
// 	return 1;
}