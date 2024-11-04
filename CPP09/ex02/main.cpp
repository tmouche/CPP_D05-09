/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:06:37 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/04 16:31:10 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.class.hpp"
#include <iostream>

int	main( void ) {
	int			array[7] = {11, 6, 8, 3, 10, 2, 4};
	PmergeMe	test(array, 7);
	
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