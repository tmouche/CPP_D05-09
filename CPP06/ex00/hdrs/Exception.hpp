/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:03:12 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/12 16:13:53 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP
# include <exception>

class	NoConvertionException : public std::exception {
public :
	char const *	what() const throw() {return "impossible";}
};

class	NoDisplayableException : public std::exception {
public :
	char const *	what() const throw() {return "Not displayable";}
};

#endif
