/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatConverter.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:00:08 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/16 13:03:46 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATCONVERTER_CLASS_HPP
# define FLOATCONVERTER_CLASS_HPP
# include <string>

class FloatConverter {
public :
	static float	converter(std::string const src);

	class	NoConvertionException {
	public :
		virtual void	what() const throw() {};
	};

private :
	FloatConverter( void );
	~FloatConverter( void );
	FloatConverter(FloatConverter const & src);

	FloatConverter&	operator=(FloatConverter const & rhs);
};

#endif