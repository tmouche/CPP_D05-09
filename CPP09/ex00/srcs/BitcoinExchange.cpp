/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:21:45 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/05 21:37:42 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"
#include "Exception.class.hpp"

#include <fstream>
#include <sstream>
#include <string>

unsigned short const	BitcoinExchange::_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
unsigned short const	BitcoinExchange::_monthLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

BitcoinExchange::BitcoinExchange( void ) {
	return ;
}

BitcoinExchange::~BitcoinExchange( void ) {
	for (std::map<RateDate&, float>::iterator it = this->_dataBase.begin(); it != this->_dataBase.end(); it++)
		delete &it->first;
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

void	BitcoinExchange::valorise(std::string const & walletFile) {
	std::string		dataStr;
	std::ifstream	ifs(walletFile.c_str());
	
	if (!ifs)
		throw NoFileException(this->_dbFile);
	std::getline(ifs, dataStr, '\n');
	if (dataStr.compare("date | value"))
		throw DatabaseErroneousData();
	while (std::getline(ifs, dataStr, '\n')) {
		std::stringstream	ssData(dataStr);
		std::string			date, price;
		int					year, month, day;
		float				fprice;
		char				temp;

		std::getline(ssData, date, '|');
		std::getline(ssData, price, '|');
		date.resize(date.size() - 1);
		if (!checkDate(date))
			throw DatabaseErroneousData();
		if (!checkPrice(price))
			throw DatabaseErroneousData();
		std::stringstream ssDate(date);
		ssDate >> year >> temp >> month >> temp >> day; 
		RateDate*	datePriced = new RateDate(year, month, day);
		if (!checkDate(*datePriced))
			throw DataBaseNoDate(datePriced);
		if (!isAlreadyPriced(*datePriced))
			throw DataBaseDuplicateDate(datePriced);
		std::stringstream	ssPrice(price);
		ssPrice >> fprice;
		this->_dataBase[*datePriced] = fprice;
	}
	return ;
}

void	BitcoinExchange::chargeDb( void ) {
	std::string		dataStr;
	std::ifstream	ifs(this->_dbFile.c_str());

	if (!ifs)
		throw NoFileException(this->_dbFile);
	std::getline(ifs, dataStr, '\n');
	if (dataStr.compare("date,exchange_rate"))
		throw DatabaseErroneousData();
	while (std::getline(ifs, dataStr, '\n')) {
		std::stringstream	ssData(dataStr);
		std::string			date, price;
		int					year, month, day;
		float				fprice;
		char				temp;

		std::getline(ssData, date, ',');
		std::getline(ssData, price, ',');
		if (!checkDate(date))
			throw DatabaseErroneousData();
		if (!checkPrice(price))
			throw DatabaseErroneousData();
		std::stringstream ssDate(date);
		ssDate >> year >> temp >> month >> temp >> day; 
		RateDate*	datePriced = new RateDate(year, month, day);
		if (!checkDate(*datePriced))
			throw DataBaseNoDate(datePriced);
		if (!isAlreadyPriced(*datePriced))
			throw DataBaseDuplicateDate(datePriced);
		std::stringstream	ssPrice(price);
		ssPrice >> fprice;
		this->_dataBase[*datePriced] = fprice;
	}
	return ;
}

bool	BitcoinExchange::isAlreadyPriced(RateDate const & date) {
	for (std::map<RateDate&, float>::iterator it = this->_dataBase.begin(); it != this->_dataBase.end(); it++) {
		if (it->first.year == date.year 
			&& it->first.month == date.month 
			&& it->first.day == date.day)
			return true;
	}
	return false;
}

bool	BitcoinExchange::checkPrice(std::string const & price) {
	std::string corpus = "0123456789";
	bool		res = true;
	bool		coma = false;

	for (int iPrice = 0; iPrice < price.size() && res == true; ++iPrice) {
		if (price[iPrice] == '.' && iPrice) {
			if (coma == false) {
				coma = true;
				continue ;
			}
		}
		else if (!corpus.find(price[iPrice]))
			continue;
		res = false;
	}
	return res;
}

bool	BitcoinExchange::checkDate(std::string const & date) {
	std::string	exemple = "XXXX-XX-XX";
	std::string	corpus = "0123456789";
	bool		res = true;

	if (date.size() != exemple.size())
		res = false;
	for (int iDate = 0, iExemple = 0; iDate < date.size() && res == true; ++iDate, ++iExemple) {
		if (date[iDate] == exemple[iExemple] || (exemple[iExemple] == 'X' && !corpus.find(date[iDate])))
			continue;
		res = false;
	}
	return res;
}

bool	BitcoinExchange::checkDate(RateDate const & date) {
	bool	leap = false;

	if	((date.year % 4 && date.year % 100) || date.year % 400)
		leap = true;
	if (date.month < 1 || date.month > 12 || date.day < 1)
		return false;
	if (leap == true && this->_monthLeap[date.month] < date.day)
		return false;
	else if (leap == false && this->_month[date.month] < date.day)
		return false;
	return true;
}
