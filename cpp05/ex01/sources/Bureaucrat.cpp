/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:20:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/26 17:02:24 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default name"), _grade(150) {

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {

}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) {
	*this = cpy;
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	this->_grade = rhs._grade;
	return (*this);
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()  {
	return((char*)"grade too high !");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()  {
	return((char*)"grade too low !");
}

void	Bureaucrat::incrementGrade() {
	if (this->_grade == 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else {
		std::cout << "congrats you've been graded !" << std::endl;
		this->_grade--;
	}
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade == 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		this->_grade++;
	}
}

void	Bureaucrat::signForm(Form &Form) {
	try {
		Form.beSigned(*this);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &Bureaucrat) {
	o << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;;
	return (o);
}
