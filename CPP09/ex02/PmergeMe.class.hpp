/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:51:17 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/14 20:12:11 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP
# include <vector>

class PmergeMe {
public:
	~PmergeMe( void );
	PmergeMe(int const * array, int const arraySize);
	PmergeMe(PmergeMe const & src);
	
	PmergeMe&	operator=(PmergeMe const & rhs);

	void	doubleSortMyNumber( void );
	void	vectorSortMyNumber( void );
	
private:
	PmergeMe( void );

	void	divideVector(std::vector<int> const & numerator);
	bool	mergeSingleVector( void );
	void	merger( void );
	std::vector<std::vector<int>*>::iterator	binarySearch(std::vector<std::vector<int>*> & container, int const num, int const start, int const end);

	std::vector<int>				_myVector;
	std::vector<std::vector<int>* >	_myVectorContainer;
	int const						_arraySize;
	float							_VectorTime;

};

#endif