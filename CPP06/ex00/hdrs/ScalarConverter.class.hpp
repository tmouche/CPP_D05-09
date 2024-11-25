/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:18:28 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/16 12:41:21 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP
# include <string>

class ScalarConverter {

public :
	static void	convert(std::string input);

private :
	ScalarConverter( void );
	~ScalarConverter( void );
	ScalarConverter(ScalarConverter const & src);

	ScalarConverter&	operator=(ScalarConverter const & rhs);
};

#endif
