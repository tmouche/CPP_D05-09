/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:21:59 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/14 18:56:22 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CLASS_CPP
# define RPN_CLASS_CPP
# include <iostream>
# include <stack>
# include <string>

class RPN {
public:
	RPN( void );
	~RPN( void );
	RPN(RPN const & src);
	RPN&	operator=(RPN const & rhs);

	int	calculRPN(std::string data);
	
private:
	bool	checkString(std::string const data, std::string const corpus) const;
	void	number(std::string& data);
	void	addition(int& temp);
	void	subtraction(int& temp);
	void	multiplication(int& temp);
	void	division(int& temp);

	void	(RPN::*_fctPtr[4])(int&);
	std::stack<int>	_myStack;	
};

#endif
