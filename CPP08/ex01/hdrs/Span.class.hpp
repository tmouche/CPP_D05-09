/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:33:12 by tmouche           #+#    #+#             */
/*   Updated: 2025/03/20 10:50:48 by thibaud          ###   ########.fr       */
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
	
	void	defSpan( void );

	std::vector<int>	_myVector;
	unsigned int		_longest;
	unsigned int		_shortest;
	unsigned int const	_size;
};

#endif
