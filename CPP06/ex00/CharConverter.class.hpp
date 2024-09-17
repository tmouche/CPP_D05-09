/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConverter.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:00:08 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/17 05:24:04 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARCONVERTER_CLASS_HPP
# define CHARCONVERTER_CLASS_HPP
# include <string>

class CharConverter {
public :
	static char	convert(std::string src);

private :
	CharConverter( void );
	~CharConverter( void );
	CharConverter(CharConverter const & src);

	CharConverter&	operator=(CharConverter const & rhs);
};

#endif