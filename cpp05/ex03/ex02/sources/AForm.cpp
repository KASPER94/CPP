/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:55:04 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 21:52:09 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("Default"), _signature(false), _gradeToSign(150), _gradeToExe(150) {
	std::cout << "Default Form created with the lowest grade (150) for signing and executing !" << std::endl;
}

AForm::AForm(std::string name, bool sign, const int gradeToSign, const int gradeToExe) : _name(name), _signature(sign), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe) {
	if (gradeToSign < 1 || gradeToExe < 1)
		throw FormGradeTooHighException();
	else if (gradeToSign > 150 || gradeToExe > 150)
		throw FormGradeTooLowException();
	std::cout << "Form " << name << " created with required grade for signing: " << gradeToSign;
	std::cout << " and for executing: " << gradeToExe << std::endl;
}

AForm::~AForm() {
	std::cout << "Form " << this->_name;
	if (this->getSignature())
		std::cout << " signed";
	else
		std::cout << " not signed";
	std::cout << " destructed" << std::endl;
}

AForm::AForm(const AForm &cpy): _name(cpy._name), _signature(cpy._signature), _gradeToSign(cpy._gradeToSign), _gradeToExe(cpy._gradeToExe) {
	std::cout << "Form " << cpy.getName();
	if (this->getSignature())
		std::cout << " signed";
	else
		std::cout << "  not signed";
	std::cout << " with required grade to sign: " << cpy.getGradeToSign();
	std::cout << " and grade to execute: " << cpy.getGradeToExe();
	std::cout << " copied" << std::endl;
}

AForm &AForm::operator=(const AForm &rhs) {
	if (this != &rhs) {
		this->_signature = rhs._signature;
	}
	std::cout << "Form " << rhs.getName();
	if (rhs.getSignature())
		std::cout << " signed";
	else
		std::cout << "  not signed";
	std::cout << " with required grade to sign: " << rhs.getGradeToSign();
	std::cout << " and grade to execute: " << rhs.getGradeToExe();
	std::cout << " copied by assignment operator" << std::endl;
	return (*this);
}

const char	*AForm::FormGradeTooHighException::what() const throw() {
	return ((char *)"Form's grade is too high !");
}

const char	*AForm::FormGradeTooLowException::what() const throw() {
	return ((char *)"Form's grade is too low !");
}

const char	*AForm::FormAlreadySigned::what() const throw() {
	return ((char *)"Form is already signed !");
}

const char	*AForm::NotSignedException::what() const throw() {
	return ((char *)"Unable to execute: form not signed.");
}

std::string AForm::getName(void) const {
	return (this->_name);
}

bool	AForm::getSignature(void) const {
	return (this->_signature);
}

int	AForm::getGradeToExe(void) const {
	return (this->_gradeToExe);
}

int	AForm::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

void	AForm::beSigned(Bureaucrat &Bureaucrat) {
	if (this->getSignature())
		throw AForm::FormAlreadySigned();
	if (Bureaucrat.getGrade() <= this->getGradeToSign()) {
		this->_signature = true;
		std::cout << "Form signed !" << std::endl;
	}
	else {
		std::cout << Bureaucrat.getName() << " couldn't sign " << this->getName() << " because ";
		throw Bureaucrat::GradeTooLowException();
		std::cout << "you must find a Bureaucrat with the grade to sign : " << this->getGradeToSign() << std::endl;
	}
	this->_signature = true;
}

std::ostream	&operator<<(std::ostream &o, const AForm &Form) {
	if (Form.getSignature())
		o << "Form " << Form.getName() << ", signed";
	else
		o << "Form " << Form.getName() << ", not signed";
	o << ", required grade for signing: " << Form.getGradeToSign();
	o << ", required grade for executing: " << Form.getGradeToExe();
	return (o);
}
