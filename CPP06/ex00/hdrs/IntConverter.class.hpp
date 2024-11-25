/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConverter.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:00:08 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/16 13:03:46 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTCONVERTER_CLASS_HPP
# define INTCONVERTER_CLASS_HPP
# include <string>

class IntConverter {
public :
	static int	converter(std::string src);

	class	NoConvertionException {
	public :
		virtual void	what() const throw() {};
	};

private :
	IntConverter( void );
	~IntConverter( void );
	IntConverter(IntConverter const & src);

	IntConverter&	operator=(IntConverter const & rhs);
};

#endif