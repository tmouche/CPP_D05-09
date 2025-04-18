/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:21:45 by tmouche           #+#    #+#             */
/*   Updated: 2025/04/18 02:41:13 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"
#include "Exception.class.hpp"

#include <fstream>

unsigned short const	BitcoinExchange::_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
unsigned short const	BitcoinExchange::_monthLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

BitcoinExchange::BitcoinExchange( void ) {
	return ;
}

BitcoinExchange::~BitcoinExchange( void ) {
	for (std::map<RateDate*, float>::iterator it = this->_dataBase.begin(); it != this->_dataBase.end(); it++)
		delete it->first;
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
		for (std::map<RateDate*, float>::iterator it; it != rhs._dataBase.end(); it++)
			this->_dataBase[(new RateDate(*it->first))] = it->second;
	}
	(void)rhs;
	return *this;
}

void	BitcoinExchange::valorise(std::string const & walletFile) {
	std::stringstream	data(this->dumpFile(walletFile));
	std::string			dataStr;
	
	std::getline(data, dataStr, '\n');
	if (dataStr.compare("date | value"))
		throw DatabaseErroneousData();
	dataStr.clear();
	while (std::getline(data, dataStr, '\n') && dataStr[0]) {
		std::stringstream	ssData(dataStr);
		std::string			date, amount;
		float				famount;

		std::getline(ssData, date, '|');
		std::getline(ssData, amount, '|');
		date.resize(date.size() - 1);
		RateDate*	datePriced = createDate(date);
		if (!checkDate(date) || !checkPrice(amount) || !checkDate(*datePriced))
			std::cout << "Error: bad input => " << dataStr << std::endl;
		else {
			std::stringstream	ssPrice(amount);
			ssPrice >> famount;
			if (famount > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else if (famount < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else
				displayLine(date, famount, getPrice(*datePriced));
		}
		delete datePriced;
		dataStr.clear();
	}
	return ;
}

void	BitcoinExchange::chargeDb( void ) {
	std::stringstream	data(this->dumpFile(this->_dbFile));
	std::string			dataStr;

	std::getline(data, dataStr, '\n');
	if (dataStr.compare("date,exchange_rate"))
		throw DatabaseErroneousData();
	dataStr.clear();
	while (std::getline(data, dataStr, '\n') && dataStr[0]) {
		std::stringstream	ssData(dataStr);
		std::string			date, price;
		float				fprice;
		
		std::getline(ssData, date, ',');
		std::getline(ssData, price, ',');
		if (!checkDate(date) || !checkPrice(price))
			throw DatabaseErroneousData();
		RateDate*	datePriced = createDate(date);
		if (!checkDate(*datePriced))
			throw DataBaseNoDate(datePriced);
		if (isAlreadyPriced(*datePriced))
			throw DataBaseDuplicateDate(datePriced);
		std::stringstream	ssPrice(price);
		ssPrice >> fprice;
		this->_dataBase[datePriced] = fprice;
		dataStr.clear();
	}
	return ;
}

void	BitcoinExchange::displayLine(std::string const & date, float amount, float price) {
	std::cout << date << " " << "=> " << amount << " = " << amount * price << std::endl;
	return ;	
}

RateDate*	BitcoinExchange::createDate(std::string const & date) {
	std::stringstream	ssDate(date);
	int					year, month, day;
	char				temp;

	ssDate >> year >> temp >> month >> temp >> day;
	RateDate*	datePriced = new RateDate(year, month, day);
	return datePriced;
}

float	BitcoinExchange::getPrice(RateDate const & date) {
	for (std::map<RateDate*, float>::iterator it = this->_dataBase.begin(); it != this->_dataBase.end(); it++) {
		if (date.year <= it->first->year && date.month <= it->first->month && date.day <= it->first->day) {
			float	price = 0.;
			if (it != this->_dataBase.begin())
				price = (--it)->second;
			return price;
		}
	}
	return this->_dataBase.end()->second;
}

bool	BitcoinExchange::isAlreadyPriced(RateDate const & date) {
	for (std::map<RateDate*, float>::iterator it = this->_dataBase.begin(); it != this->_dataBase.end(); it++) {
		if (it->first->year == date.year 
			&& it->first->month == date.month 
			&& it->first->day == date.day)
			return true;
	}
	return false;
}

bool	BitcoinExchange::checkPrice(std::string const & price) {
	std::string corpus = "0123456789";
	int const	priceSize = price.size();
	bool		res = true;
	bool		coma = false;

	for (int iPrice = 1; iPrice < priceSize && res == true; ++iPrice) {
		if (price[iPrice] == '.' && iPrice) {
			if (coma == false) {
				coma = true;
				continue ;
			}
		}
		else if (corpus.find(price[iPrice]) != std::string::npos)
			continue;
		res = false;
	}
	return res;
}

bool	BitcoinExchange::checkDate(std::string const & date) {
	std::string	exemple = "XXXX-XX-XX";
	std::string	corpus = "0123456789";
	int const	dateSize = date.size();
	bool		res = true;

	if (date.size() != exemple.size())
		res = false;
	for (int iDate = 0, iExemple = 0; iDate < dateSize && res == true; ++iDate, ++iExemple) {
		if (date[iDate] == exemple[iExemple] || (exemple[iExemple] == 'X' && corpus.find(date[iDate]) != std::string::npos))
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
	if (leap == true && this->_monthLeap[date.month - 1] < date.day)
		return false;
	else if (leap == false && this->_month[date.month - 1] < date.day)
		return false;
	return true;
}

std::string	BitcoinExchange::dumpFile(std::string const & name) {
	std::ifstream	ifs(name.c_str());
	std::string		data;

	if (!ifs)
		throw NoFileException(name);
	std::getline(ifs, data, '\0');
	ifs.close();
	return data;
}