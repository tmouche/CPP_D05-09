/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:51:17 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/11 19:55:16 by tmouche          ###   ########.fr       */
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
	void	binarySearch(std::vector<std::vector<int>*> & container, std::vector<int> const & insert);
	std::vector<int>				_myVector;
	std::vector<std::vector<int>* >	_myVectorContainer;
	int const						_arraySize;
	float							_VectorTime;

};

#endif