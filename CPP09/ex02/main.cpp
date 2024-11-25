/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:06:37 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/25 19:44:36 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.template.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>

bool	checkData(char **data, std::string corpus) {
	for (int str = 0; data[str]; str++) {
		for (int idx = 0; data[str][idx]; idx++) {
			int idx_corpus;
			for (idx_corpus = 0; corpus[idx_corpus]; idx_corpus++) {
				if (data[str][idx] == corpus[idx_corpus])
					break ;
			}
			if (!corpus[idx_corpus])
				return false;
		}
	}
	return true;
}

int	main(int ac, char **av) {

	if (ac < 2 || !checkData(&av[1], "0123456789")) {
		std::cout << "Bad Argument" << std::endl;
		return 1;
	}
	std::cout << "Before:";
	for (int idx = 1; idx < ac; idx++)
		std::cout << " " << av[idx];
	std::cout << std::endl;
	struct timeval	sw;
	gettimeofday(&sw, NULL);
	size_t const preV = sw.tv_usec;
	PmergeMe<std::vector<std::vector<int>*>, std::vector<int> >	testVector(&av[1]);
	std::vector<int> resVector = *testVector.SortMyNumbers();
	gettimeofday(&sw, NULL);
	size_t const postV = sw.tv_usec;
	int const	sizeVector = resVector.size();
	std::cout << "After:";
	for (int idx = 0; idx < sizeVector; idx++) {
		std::cout << " "<< resVector[idx];
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector: " << static_cast<float>(postV - preV) / 100000 << "us" << std::endl;
	
	gettimeofday(&sw, NULL);
	size_t const preD = sw.tv_usec;
	PmergeMe<std::deque<std::deque<int>*>, std::deque<int> > testDeque(&av[1]);
	std::deque<int> resDeque = *testDeque.SortMyNumbers();
	gettimeofday(&sw, NULL);
	size_t const postD = sw.tv_usec;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque: " << static_cast<float>(postD - preD) / 100000 << "us" << std::endl;
	
	return 1;
}