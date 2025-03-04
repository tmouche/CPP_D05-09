/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:33:12 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/25 12:24:21 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP
# include <vector>
# include <string>

typedef std::vector<int>::const_iterator spanIterator;

class Span {
public :
	~Span( void );
	Span(unsigned int N);
	Span(Span const & src);
	
	Span&	operator=(Span const & rhs);

	class NoSuchSpaceLeftException {
		public :
			std::string what( void ) const throw();
	};
	
	class 	NotEnoughElementException {
		public :
			std::string what( void ) const throw();
	};
	
	void			addNumber(int const num);
	void			addNumber(spanIterator start, spanIterator end);
	unsigned int	shortestSpan( void ) const;
	unsigned int	longestSpan( void ) const;

private :
	Span( void );

	std::vector<int>	_myVector;
	unsigned int const	_size;
};

#endif
