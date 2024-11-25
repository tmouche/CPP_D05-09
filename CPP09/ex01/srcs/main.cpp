/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:52:50 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/25 19:51:33 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.class.hpp"
#include <iostream>
#include <string>

int	main(int ac, char** av) {
	RPN		test;
	int 	res;
	
	(void)ac;
	if (ac != 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	try {res = test.calculRPN(av[1]);}
	catch (std::exception& e) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	std::cout << res << std::endl;
	return 0;
}