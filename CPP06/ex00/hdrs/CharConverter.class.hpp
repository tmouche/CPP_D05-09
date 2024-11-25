/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConverter.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:00:08 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/22 15:39:49 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARCONVERTER_CLASS_HPP
# define CHARCONVERTER_CLASS_HPP
# include <string>

class CharConverter {
public :
	static char	converter(std::string const src);

	class	NoConvertionException {
	public :
		virtual void	what() const throw() {};
	};

	class	NoDisplayableException {
	public :
		virtual void	what() const throw() {};
	};

private :
	CharConverter( void );
	~CharConverter( void );
	CharConverter(CharConverter const & src);

	CharConverter&	operator=(CharConverter const & rhs);
};

#endif