/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:06:37 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/06 18:26:19 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.class.hpp"
#include <iostream>

int	main( void ) {
	int			array[100] = {113, 364, 160, 49, 952, 874, 621, 973, 597, 93, 980, 3, 828, 432, 333, 228, 927, 933, 69, 554, 407, 650, 675, 696, 496, 331, 646, 674, 1000, 439, 642, 350, 159, 247, 394, 578, 928, 169, 19, 287, 525, 947, 429, 711, 737, 705, 763, 505, 9, 992, 774, 476, 117, 689, 236, 637, 771, 740, 86, 334, 110, 275, 138, 610, 808, 156, 470, 399, 149, 335, 833, 15, 956, 64, 12, 931, 140, 50, 471, 899, 617, 669, 563, 688, 358, 262, 415, 684, 499, 294, 537, 477, 745, 377, 915, 510, 639, 870, 314, 586};
	PmergeMe	test(array, 100);
	
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