/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:31:10 by thibaud           #+#    #+#             */
/*   Updated: 2025/05/22 10:29:03 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"

#include <iostream>

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Need a wallet as input.." << std::endl;
		return 1;
	}
	try {
		BitcoinExchange	myWallet("data.csv");
		myWallet.chargeDb();
		myWallet.valorise(av[1]);
	} catch (std::exception& e) {
		return 1;
	}
	return 0;
}