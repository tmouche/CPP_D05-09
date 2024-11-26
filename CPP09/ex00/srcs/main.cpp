/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:12:30 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/12 19:25:19 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"
#include <iostream>

int	main(int ac, char **av) {
	BitcoinExchange	testClass;

	if (ac != 2) {
		std::cout << "Error: wrong argument" << std::endl;
		return 1;
	}
	try {testClass.valueMyWallet(av[1], "data.csv");}
	catch (BitcoinExchange::FileException& e) {e.what();}
	return 0;
}
