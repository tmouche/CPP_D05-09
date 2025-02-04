/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:21:45 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/04 19:23:11 by tmouche          ###   ########.fr       */
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
		float				price;

		
	}
	return ;
}

bool	BitcoinExchange::checkPart(std::string const & line) {
	std::string const	corpus = "0123456789";
	std::string const	exemple = "XXXX-XX-XX,XX.XX";
	int					iLine;
	int					iExemple;

	for (iLine = 0, iExemple = 0; iLine < line.size();) {
		if (line[iLine] == exemple[iExemple]) {
			++iLine;
			++iExemple; 
		}
		else if (exemple[iExemple] == 'X') {
			if (corpus.find(line[iLine])) {
				++iLine;
				++iExemple;
			}
			else
				return false;
		}
		else if (exemple[iExemple] == '*') {
			if (corpus.find(line[iLine]))
				++iLine;
			else
				++iExemple;
		}
		else
			return false;
	}
	if (iExemple < exemple.size() - 1)
		return false;
	return true;
}
