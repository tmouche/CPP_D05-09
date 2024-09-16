/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConverter.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:00:08 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/16 13:03:46 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARCONVERTER_CLASS_HPP
# define CHARCONVERTER_CLASS_HPP
# include <string>

class CharConverter {
public :
	static bool	itsChar(std::string src);

private :
	CharConverter( void );
	~CharConverter( void );
	CharConverter(CharConverter const & src);

	CharConverter&	operator=(CharConverter const & rhs);
};

#endif