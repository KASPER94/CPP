/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:55:04 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/26 17:12:44 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, bool sign, const int grade, const int reqGrade) : _name(name), _signature(sign), _grade(grade), _requiredGrade(reqGrade) {

}

Form::~Form() {

}

Form::Form(const Form &cpy): _name(cpy._name), _signature(cpy._signature), _grade(cpy._grade), _requiredGrade(cpy._requiredGrade) {
	// *this = cpy;
}

Form &Form::operator=(const Form &rhs) {
	if (this != &rhs) {
		this->_signature = rhs._signature;
	}
	return (*this);
}

int	Form::getGrade() const {
	return (this->_grade);
}

bool	Form::beSigned(Bureaucrat &Bureaucrat) {
	if (Bureaucrat.getGrade() <= this->getGrade()) {
		this->_signature = true;
	}
	else {
		this->_signature = false;
	}
	return (this->_signature);
}

