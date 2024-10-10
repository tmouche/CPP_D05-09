/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:12:30 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/10 20:29:19 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"

int	main(int ac, char **av) {
	BitcoinExchange	testClass;

	testClass.dataLoader();
	testClass.valueMyWallet(av[1]);
	return 1;
}
