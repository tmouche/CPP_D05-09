/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:31:29 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/09 22:11:34 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP
# include <string>

class Bureaucrat;

class Form {
public :
	~Form( void );
	Form(std::string name, int gradeSign, int gradeExecute);
	Form(Form const & src);
	
	Form&	operator=(Form const & rhs);

	class GradeTooHighException {
	public :
		virtual const void	what() const throw() {};
	};

	class GradeTooLowException {
	public :
		virtual const void	what() const throw() {};
	};
	
	std::string	getName( void ) const;
	bool		getSigned( void ) const;
	int			getGradeSign( void ) const;
	int			getGradeExectute( void ) const;

	void	beSigned(Bureaucrat const & src);

private :
	Form( void );

	std::string	const	_name;
	bool				_signed;
	int const			_gradeSign;
	int const			_gradeExecute;

};

std::ostream&	operator<<(std::ostream& out, Form const & rhs);

#endif
