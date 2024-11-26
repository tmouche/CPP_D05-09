/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:17:29 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/26 16:41:00 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_CLASS_HPP
# define BITCOINEXCHANGE_CLASS_HPP
# include <vector>
# include <string>
#include <iostream>

class BitcoinExchange {
public : 
	BitcoinExchange( void );
	~BitcoinExchange( void );
	BitcoinExchange(BitcoinExchange const & src);

	BitcoinExchange&	operator=(BitcoinExchange const & rhs);

	void	valueMyWallet(std::string inFile, std::string dataFile);

	class	Exception {
	public :
		virtual const void	what( void ) const throw() {}
	};
	
	class	inputException {
	public :
		virtual const void	what(std::string input) const throw() {
			std::cout << "Error: bad input => " << input << std::endl;
		}
	};

	class	TooLargeValueException {
	public :
		virtual const void	what( void ) const throw() {
			std::cout << "Error: too large number." << std::endl;
		};
	};

	class	NegativeValueException {
	public :
		virtual const void	what( void ) const throw() {
			std::cout << "Error: not a positive number." << std::endl;
		};
	};
	
	class	FileException {
	public :
		virtual const void	what( void ) const throw() {
			perror("Error");
		}
	};

private :
	void	dataLoader(std::string dataFile);
	int		convertDate(std::string date) const;
	bool	checkString(std::string const seed, std::string const data, std::string const corpus) const;
	int		dateToIdx(int const dateConverted) const;
	void	lineValue(std::string line);
	
	std::vector<float>_dataBaseDate;
	std::vector<float>_dataBaseRate;

	static int const	_month[12];
	static int const	_monthLeap[12];
};

#endif