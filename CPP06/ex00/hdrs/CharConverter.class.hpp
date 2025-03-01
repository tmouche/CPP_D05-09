/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConverter.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:00:08 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/12 16:09:28 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARCONVERTER_CLASS_HPP
# define CHARCONVERTER_CLASS_HPP
# include <string>

class CharConverter {
public :
	static char	converter(std::string const src);

private :
	CharConverter( void );
	~CharConverter( void );
	CharConverter(CharConverter const & src);

	CharConverter&	operator=(CharConverter const & rhs);
};

#endif