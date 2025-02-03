/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:21:45 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/03 21:47:25 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"
#include "Exception.class.hpp"

#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange( void ) {
	return ;
}

BitcoinExchange::~BitcoinExchange( void ) {
	return ;
}

BitcoinExchange::BitcoinExchange(std::string const & file) : _dbFile(file) {
	this->chargeDb();
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
	*this = src;
	return ;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	if (this != &rhs) {
		for (std::map<RateDate&, float>::iterator it; it != rhs._dataBase.end(); it++)
			this->_dataBase[*(new RateDate(it->first))] = it->second;
	}
	return *this;
}

void	BitcoinExchange::chargeDb( void ) {
	std::string		dataStr;
	std::ifstream	ifs(this->_dbFile.c_str());
	
	if (!ifs)
		throw NoFileException(this->_dbFile);
	std::getline(ifs, dataStr, '\n');
	dataStr.clear();
	std::getline(ifs, dataStr, '\n');
	while (!dataStr.empty()) {
		std::stringstream	ssData(dataStr);
		t_ssPart			part;
		float				price;

		ssData >> part.year >> part.dash[0] >> part.month >> part.dash[1] >> part.day >> part.coma >> price;
	}
	return ;
}

void	BitcoinExchange::checkPart(t_ssPart& part) {
	if (part.year || part.month || part.day || part.dash[0] != )
}