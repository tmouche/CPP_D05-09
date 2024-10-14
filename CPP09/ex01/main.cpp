/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:52:50 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/14 18:57:10 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.class.hpp"
#include <iostream>
#include <string>

int	main(int ac, char** av) {
	RPN	test;
	
	(void)ac;
	std::cout << test.calculRPN(av[1]) << std::endl;
	return 1;
}