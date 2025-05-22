/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:21:45 by tmouche           #+#    #+#             */
/*   Updated: 2025/05/22 10:29:16 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"

#include <fstream>
#include <iostream>
#include <exception>

unsigned short const	BitcoinExchange::_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
unsigned short const	BitcoinExchange::_monthLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

BitcoinExchange::BitcoinExchange( void ) {
	return ;
}

BitcoinExchange::~BitcoinExchange( void ) {
	for (std::set<RateDate*>::iterator it = this->_dataBase.begin(); it != this->_dataBase.end(); it++)
		delete *it;
	return ;
}

BitcoinExchange::BitcoinExchange(std::string const & file) : _dbFile(file) {
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
	*this = src;
	return ;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	if (this != &rhs) {
		for (std::set<RateDate*>::iterator it = rhs._dataBase.begin(); it != rhs._dataBase.end(); it++)
			this->_dataBase.insert(new RateDate(**it));
	}
	return *this;
}

void	BitcoinExchange::valorise(std::string const & walletFile) {
	std::stringstream	data(this->dumpFile(walletFile));
	std::string			dataStr;
	
	std::getline(data, dataStr, '\n');
	if (dataStr.compare("date | value")) {
		std::cout << "Error: missing header in wallet" << std::endl;
		throw std::exception();
	}
	dataStr.clear();
	while (std::getline(data, dataStr, '\n') && data.str().size()) {
		std::stringstream	ssData(dataStr);
		std::string			date, amount;
		float				famount;

		std::getline(ssData, date, '|');
		std::getline(ssData, amount, '\n');
		if (date.size())
			date.resize(date.size() - 1);
		RateDate*	datePriced = createDate(date, 0.0);
		if (!checkDate(date) || !checkPrice(amount) || !checkDate(datePriced))
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
		if (datePriced)
			delete datePriced;
		dataStr.clear();
	}
	return ;
}

void	BitcoinExchange::chargeDb( void ) {
	std::stringstream	data(this->dumpFile(this->_dbFile));
	std::string			dataStr;

	std::getline(data, dataStr, '\n');
	if (dataStr.compare("date,exchange_rate")) {
		std::cout << "Error: missing database's header" << std::endl;
		throw std::exception();
	}
	dataStr.clear();
	while (std::getline(data, dataStr, '\n') && dataStr[0]) {
		std::stringstream	ssData(dataStr);
		std::string			date, price;
		float				fprice;
		
		std::getline(ssData, date, ',');
		std::getline(ssData, price, ',');
		if (!checkDate(date) || !checkPrice(price)) {
			std::cout << "Error: unknow token in database" << std::endl;
			throw std::exception();
		}
		std::stringstream	ssPrice(price);
		ssPrice >> fprice;
		if (fprice < 0.) {
			std::cout << "Error: a price can not be negative in database" << std::endl;
			throw std::exception();
		}
		RateDate*	datePriced = createDate(date, fprice);
		if (!checkDate(datePriced)) {
			if (datePriced)
				delete datePriced;
			std::cout << "Error: Erroneous date in database" << std::endl;
			throw std::exception();
		}
		if (isAlreadyPriced(*datePriced)) {
			delete datePriced;
			std::cout << "Error: Date already priced in database" << std::endl;
			throw std::exception();
		}
		this->_dataBase.insert(datePriced);
		dataStr.clear();
	}
	return ;
}

void	BitcoinExchange::displayLine(std::string const & date, float amount, float price) {
	std::cout << date << " " << "=> " << amount << " = " << amount * price << std::endl;
	return ;	
}

RateDate*	BitcoinExchange::createDate(std::string const & date, float const price) {
	std::stringstream	ssDate(date);
	int					year, month, day;
	char				temp;

	if (date.empty())
		return NULL;
	ssDate >> year >> temp >> month >> temp >> day;
	RateDate*	datePriced = new RateDate(year, month, day, price);
	return datePriced;
}

float	BitcoinExchange::getPrice(RateDate &date) {
	std::set<RateDate*>::iterator	it;

	it = this->_dataBase.find(&date);
	if (it != this->_dataBase.end())
		return (*it)->price;
	it = this->_dataBase.lower_bound(&date);
	if (it != this->_dataBase.begin()) {
		return (*(--it))->price;
	}
	return 0.0;
}

bool	BitcoinExchange::isAlreadyPriced(RateDate& date) {
	if (this->_dataBase.find(&date) != this->_dataBase.end())
		return true;
	return false;
}

bool	BitcoinExchange::checkPrice(std::string & price) {
	std::string corpus = "0123456789";
	bool		coma = false;

	while (price.size() > 0 && *(price.begin()) == ' ')
		price.erase(0, 1);
	int const	priceSize = price.size();
	bool		res = price.size() ? true : false;
	for (int iPrice = 0; iPrice < priceSize && res == true; ++iPrice) {
		if (price[iPrice] == '.' && iPrice) {
			if (coma == false) {
				coma = true;
				continue ;
			}
		}
		else if (corpus.find(price[iPrice]) != std::string::npos || (iPrice == 0 && price[iPrice] == '-'))
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

bool	BitcoinExchange::checkDate(RateDate const * date) {
	bool	leap = false;

	if (!date)
		return false;
	if	((!(date->year % 4) && date->year % 100) || !(date->year % 400))
		leap = true;
	if (date->month < 1 || date->month > 12 || date->day < 1)
		return false;
	if (leap == true && this->_monthLeap[date->month - 1] < date->day)
		return false;
	else if (leap == false && this->_month[date->month - 1] < date->day)
		return false;
	return true;
}

std::string	BitcoinExchange::dumpFile(std::string const & name) {
	std::ifstream	ifs(name.c_str());
	std::string		data;

	if (!ifs) {
		std::cout << "Error: No such file or directory " << name << std::endl;
		throw std::exception();
	}
	std::getline(ifs, data, '\0');
	ifs.close();
	return data;
}