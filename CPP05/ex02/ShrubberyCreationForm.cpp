/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 03:56:19 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/11 05:14:21 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.class.hpp"
#include "Bureaucrat.class.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) {
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
	this->_target = target;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) {
	*this = src;
	return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
  try {
  	if (executor.getGrade() > this->getGradeSign()
  		|| executor.getGrade() > this->getGradeExecute())
  		throw AForm::GradeTooLowException();
  	else if (this->getSigned() == false)
  		throw AForm::FormNotSigned();
  	else {
  	  std::ofstream	ofs(this->_target + "_shrubbery");
  	  ofs << "                                                         .
                                                  .         ;  
                     .              .              ;%     ;;   
                       ,           ,                :;%  %;   
                        :         ;                   :;%;'     .,   
               ,.        %;     %;            ;        %;'    ,;
                 ;       ;%;  %%;        ,     %;    ;%;    ,%'
                  %;       %;%;      ,  ;       %;  ;%;   ,%;' 
                   ;%;      %;        ;%;        % ;%;  ,%;'
                    `%;.     ;%;     %;'         `;%%;.%;'
                     `:;%.    ;%%. %@;        %; ;@%;%'
                        `:%;.  :;bd%;          %;@%;'
                          `@%:.  :;%.         ;@@%;'   
                            `@%.  `;@%.      ;@@%;         
                              `@%%. `@%%    ;@@%;        
                                ;@%. :@%%  %@@%;       
                                  %@bd%%%bd%%:;     
                                    #@%%%%%:;;
                                    %@@%%%::;
                                    %@@@%(o);  . '         
                                    %@@@o%;:(.,'         
                                `.. %@@@o%::;         
                                   `)@@@o%::;         
                                    %@@(o)::;        
                                   .%@@@@%::;         
                                   ;%@@@@%::;.          
                                  ;%@@@@%%:;;;. 
                              ...;%@@@@@%%:;;;;,..    ";
  	  ofs.close();
    }
  }
  catch (AForm::GradeTooLowException& e) {
  	std::cout << executor.getName() << " couldn't execute " << this->getName() << " because his grade is too low!";
  }
  catch (AForm::FormNotSigned& e) {
  	std::cout << executor.getName() << " have to sign " << this->getName() << " before execute it!";
  }
  return ;
}
