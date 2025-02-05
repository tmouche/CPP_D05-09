/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:08:22 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/05 21:32:19 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_CLASS_HPP
# define EXCEPTION_CLASS_HPP
# include <iostream>
# include <string>

class Exception {
	public:
		virtual void	what() const throw() = 0;
};

class NoFileException : public Exception {
	public:
		NoFileException(std::string const & file) : _file(file) {}
		virtual void	what() const throw() {
			std::cout << "Error: No such file " << this->_file << std::endl; 
		}
	private:
		std::string const &	_file;
};

class DatabaseErroneousData: public Exception {
	public:
		virtual void	what() const throw() {
			std::cout << "Error: Unknown char in database " <<  std::endl;
		}
};

class DataBaseNoDate : public Exception {
	public:
		DataBaseNoDate(RateDate* date) : _date(date) {}
		virtual void	what() const throw() {
			std::cout << "Error: " << this->_date->year << "-" << this->_date->month << "-" << this->_date->day << " does not exist" << std::endl;
			delete this->_date;
		}
	private:
		RateDate*	_date;
};

class DataBaseDuplicateDate : public Exception {
	public:
		DataBaseDuplicateDate(RateDate* date) : _date(date) {}
		virtual void	what() const throw() {
			std::cout << "Error: " << this->_date->year << "-" << this->_date->month << "-" << this->_date->day << " already exist in the database" << std::endl;
			delete this->_date;
		}
	private:
		RateDate*	_date;
};

#endif
