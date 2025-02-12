/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConverter.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:00:08 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/16 13:03:46 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLECONVERTER_CLASS_HPP
# define DOUBLECONVERTER_CLASS_HPP
# include <string>

class DoubleConverter {
public :
	static double	converter(std::string const src);

private :
	DoubleConverter( void );
	~DoubleConverter( void );
	DoubleConverter(DoubleConverter const & src);

	DoubleConverter&	operator=(DoubleConverter const & rhs);
};

#endif