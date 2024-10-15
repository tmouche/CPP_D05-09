/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:52:50 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/15 11:24:12 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.class.hpp"
#include <iostream>
#include <string>

int	main(int ac, char** av) {
	RPN		test;
	int 	res;
	
	(void)ac;
	try {res = test.calculRPN(av[1]);}
	catch (std::exception& e) {
		std::cout << "Error" << std::endl;
		return 0;
	}
	std::cout << res << std::endl;
	return 1;
}