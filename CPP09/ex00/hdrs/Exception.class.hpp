/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:08:22 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/03 21:44:20 by tmouche          ###   ########.fr       */
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

class DatabaseErroneousDatabase : public Exception {
	public:
		virtual void	what() const throw() {
			std::cout << "Error: Unknown char in database " <<  std::endl;
		}
};

class DataBaseNoDate : public Exception {
	public:
		DataBaseNoDate(std::string const & date) : _date(date) {}
		virtual void	what() const throw() {
			std::cout << "Error: " << this->_date << " does not exist" << std::endl;
		}
	private:
		std::string	const &	_date;
};

#endif
