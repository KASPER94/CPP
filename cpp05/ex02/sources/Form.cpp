/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:55:04 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/16 23:00:25 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Default"), _signature(false), _gradeToSign(150), _gradeToExe(150) {
	std::cout << "Default Form created with the lowest grade (150) for signing and executing !" << std::endl;
}

Form::Form(std::string name, bool sign, const int gradeToSign, const int gradeToExe) : _name(name), _signature(sign), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe) {
	if (gradeToSign < 1 || gradeToExe < 1)
		throw FormGradeTooHighException();
	else if (gradeToSign > 150 || gradeToExe > 150)
		throw FormGradeTooLowException();
}

Form::~Form() {

}

Form::Form(const Form &cpy): _name(cpy._name), _signature(cpy._signature), _gradeToSign(cpy._gradeToSign), _gradeToExe(cpy._gradeToExe) {
	
}

Form &Form::operator=(const Form &rhs) {
	if (this != &rhs) {
		this->_signature = rhs._signature;
	}
	return (*this);
}

const char	*Form::FormGradeTooHighException::what() const throw() {
	return ((char *)"Form's grade is too high !");
}

const char	*Form::FormGradeTooLowException::what() const throw() {
	return ((char *)"Form's grade is too low !");
}

const char	*Form::FormAlreadySigned::what() const throw() {
	return ((char *)"Form is already signed !");
}

std::string Form::getName(void) const {
	return (this->_name);
}

bool	Form::getSignature(void) const {
	return (this->_signature);
}

int	Form::getGradeToExe(void) const {
	return (this->_gradeToExe);
}

int	Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

void	Form::beSigned(Bureaucrat &Bureaucrat) {
	if (Bureaucrat.getGrade() <= this->getGradeToSign()) {
		this->_signature = true;
	}
	else {
		throw Bureaucrat::GradeTooLowException();
		std::cout << "you must find a Bureaucrat with the required grade to sign the form !" << std::endl;
	}
	if (this->getSignature())
		throw Form::FormAlreadySigned();
		
	this->_signature = true;
}

