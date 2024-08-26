/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:55:04 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/26 16:46:21 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, bool sign, const int grade, const int reqGrade) _name(name), _signature(sign), _grade(grade), _requiredGrade(reqGrade) {

}

Form::~Form() {

}

Form::Form(const Form &cpy) _name(cpy.name), _signature(cpy.sign), _grade(cpy.grade), _requiredGrade(cpy.reqGrade) {
	// *this = cpy;
}

Form &Form::operator=(const Form &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_signature = rhs._signature;
		this->_grade = rhs._grade;
		this->_grade = rhs._grade;
	}
	return (*this);
}

bool	Form::beSigned(Bureaucrat &Bureaucrat) {
	if(Bureaucrat->getGrade() <= this->getGrade()) {
		this->_
	}
}
