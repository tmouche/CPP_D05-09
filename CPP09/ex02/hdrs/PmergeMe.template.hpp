/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.template.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:46:09 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/07 13:17:38 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TEMPLATE_HPP
# define PMERGEME_TEMPLATE_HPP
# include <cstdlib>

template< typename Nc, typename Sc >
class PmergeMe {
public:
	PmergeMe( void ) {}
	~PmergeMe( void ) {}
	PmergeMe(char **data) {
		for (int idx = 0; data[idx]; idx++) {
			this->_myType.push_back(std::atoi(data[idx]));
		}
		return ;
	}
	
	PmergeMe(PmergeMe const & src) {
		*this = src;
		return ;
	}
	
	PmergeMe&	operator=(PmergeMe const & rhs) {
		if (this != &rhs) {
			this->_myType = rhs._myType;
			this->_myTypeContainer = rhs._myTypeContainer;
		}
		return *this;
	}

	Sc*	SortMyNumbers( void ) {
		if (this->_myType.size() == 1)
			return &this->_myType;
		this->divide(this->_myType);
		while (this->merge() && this->_myTypeContainer.size())
			;
		this->insert();
		int const size = this->_myTypeContainer.size();
		for (int count = 0; count < size; count++) {
			this->_myType.push_back(this->_myTypeContainer[count]->front());
			delete this->_myTypeContainer[count];
		}
		return &this->_myType;
	}

private:
	void	divide(Sc & numerator) {
		int	const numeratorSize = numerator.size();

		if (numeratorSize <= 1)
			return ;
		Sc*	container[2] = {new Sc(), new Sc()};
		for (int i = numeratorSize; i > 0; i--) {
			container[i % 2]->push_back(numerator.back());
			numerator.pop_back();
		}
		if (!this->_myTypeContainer.empty()) {
			delete this->_myTypeContainer.back();
			this->_myTypeContainer.pop_back();
		}
		this->_myTypeContainer.push_back(container[0]);
		divide(*this->_myTypeContainer.back());
		this->_myTypeContainer.push_back(container[1]);
		divide(*this->_myTypeContainer.back());
		return ;
	}
	
	bool	merge( void ) {
		Sc*	container[2] = {new Sc(*this->_myTypeContainer.back()), NULL};

		delete this->_myTypeContainer.back();
		this->_myTypeContainer.pop_back();
		if (this->_myTypeContainer.size() && this->_myTypeContainer.back()->size() < 2) {
			container[1] = new Sc(*this->_myTypeContainer.back());
			delete this->_myTypeContainer.back();
			this->_myTypeContainer.pop_back();
			int	idx = (container[0]->back() - container[1]->back() >= 0 ? 0 : 1);
			container[idx]->push_back(container[(idx + 1) % 2]->back());
			this->_myTypeContainer.insert(this->_myTypeContainer.begin(), container[idx]);
			delete container[(idx + 1) % 2];
		}
		else {
			this->_myTypeContainer.insert(this->_myTypeContainer.begin(), container[0]);
			return 0;
		}
		return 1;
	}
	
	void	insert( void ) {
		Nc	newContainer;
		Nc	lastContainer;
	                                                                                                                                              
		while (this->_myTypeContainer.size()) {
			newContainer.insert(binarySearch(newContainer, this->_myTypeContainer.back()->front(), 0, newContainer.size() - 1), this->_myTypeContainer.back());
			this->_myTypeContainer.pop_back();
		}
		int const size = newContainer.size();
		for (int idx = 0; idx < size; idx++) {
			Sc* temp = new Sc();
			temp->push_back(newContainer[idx]->front());
			lastContainer.push_back(temp);
		}
		int	jacobsthal;
		for (int idx = 0; idx < size; idx++) {
			jacobsthal = this->jacobsthalIdx(idx, size - 1);
			if (newContainer[jacobsthal]->size() == 2) {
				Sc* temp = new Sc();
				temp->push_back(newContainer[jacobsthal]->back());
				lastContainer.insert(binarySearch(lastContainer, temp->front(), 0, lastContainer.size() - 1), temp);
			}
			delete newContainer[jacobsthal];
		}
		this->_myTypeContainer = lastContainer;
		return ;
	}
	
	typename Nc::iterator	binarySearch(Nc & container, int const num, int const start, int const end) {
		typename Nc::iterator	it = container.begin() + start;
		int	const				size = end - start + 1;
		int						idx = start + size / 2;
	
		if (size < 1 || start > end)
			return it;
		else if (container[idx]->front() > num)
			return binarySearch(container, num, start, --idx);
		else if (container[idx]->front() < num)
			return binarySearch(container, num, ++idx, end);
		return it + idx;
	}

	int	jacobsthalIdx(int const idx, int const size) {
		int localIdx;

		for (localIdx = 0; idx > this->_jacobsthal[localIdx] && localIdx < 15; localIdx++);
		if (localIdx == 0)
			return 0;
		int max;
		if (this->_jacobsthal[localIdx] > size)
			max = size;
		else
			max = this->_jacobsthal[localIdx];
		int const res = max - (idx - this->_jacobsthal[localIdx - 1] - 1);
		return (res);
	}

	Sc					_myType;
	Nc					_myTypeContainer;
	static int const	_jacobsthal[20];
};

template< typename Nc, typename Sc>
const int PmergeMe<Nc, Sc>::_jacobsthal[20] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

#endif