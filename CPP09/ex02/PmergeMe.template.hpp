/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.template.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:46:09 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/18 17:53:02 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TEMPLATE_HPP
# define PMERGEME_TEMPLATE_HPP
# include <cstdlib>

template< typename<typename class container, typename T >
class PmergeMe {
public:
	PmergeMe( void ) {}
	~PmergeMe( void ) {}
	PmergeMe(char **data) {
		for (int idx = 0; data[idx]; idx++) {
			this->_myType.push_back(std::atoi(data));
		}
		return ;
	}
	PmergeMe(PmergeMe const & src) {
		return ;
	}
	
	PmergeMe&	operator=(PmergeMe const & rhs) {
		return ;
	}

	T<int>*	SortMyNumbers( void ) {
		T<int>* res = new T<int>();
	
		this->divide(this->_myType);
		while (this->merge());
		this->insert();
		int const size = this->_MyTypeContainer.size();
		for (int count = 0; count < size; count++) {
			res->push_back(this->_myTypeContainer[idx]->front());
		}
		return res;
	}

private:
	void	divide(T const & numerator) {
		int	const numeratorSize = numerator.size();

		if (numeratorSize <= 1)
			return ;
		T<int>*	container[2] = {new T<int>(), new T<int>()};
		for (int i = 0; i < numeratorSize; i++) {
			container[i % 2]->push_back(numerator[i]); 
		}
		if (!this->_myTypeContainer.empty())
			this->_myTypeContainer.pop_back();
		this->_myTypeContainer.push_back(container[0]);
		divide(*this->_myTypeContainer.back());
		this->_myVectorContainer.push_back(container[1]);
		divide(*this->_myTypeContainer.back());
		return ;
	}
	
	bool	merge( void ) {
		T<int>*	container[2] = {new T<int>(*this->_myTypeContainer.back()), NULL};

		this->_myTypeContainer.pop_back();
		if (this->_myTypeContainer.back()->size() < 2) {
			container[1] = new T<int>(*this->_myTypeContainer.back());
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
		T<T<int>*>	newContainer;
		T<T<int>*>	lastContainer;
	
		while (this->_myTypeContainer.size()) {
			newContainer.insert(binarySearch(newContainer, this->_myVectorContainer.back()->front(), 0, newContainer.size() - 1), this->_myVectorContainer.back());
			this->_myTypeContainer.pop_back();
		}
		int const size = newContainer.size();
		for (int idx = 0; idx < size; idx++) {
			T<int>* temp = new T<int>();
			temp->push_back(newContainer[idx]->front());
			lastContainer.push_back(temp);
		}
		for (int idx = 0; idx < size; idx++) {
			T<int>* temp = new T<int>();
			temp->push_back(newContainer[idx]->back());
			lastContainer.insert(binarySearch(lastContainer, temp->front(), 0, lastContainer.size() - 1), temp);
		}
		this->_myTypeContainer = lastContainer;
		return ;
	}
	
	T<T<int>*>::iterator	binarySearch(T<T<int>*> & container, int const num, int const start, int const end) {
		T<T<int>*>::iterator	it = container.begin() + start;
		int	const				size = end - start + 1;
		int						idx = start + size / 2;
	
		if (size < 1 || start > end)
			return it;
		else if (container[idx]->front() > num)
			return binarySearch(container, num, start, --idx);
		else if (container[idx]->front() < num)
			return binarySearch(container, num, ++idx, end);
		return it + start;
	}

	T<int>		_myType;
	T<T<int>*>	_myTypeContainer;
	int const	_Size;
};

#endif