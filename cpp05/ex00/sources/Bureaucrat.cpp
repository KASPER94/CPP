/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:20:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 15:25:08 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default name"), _grade(150) {
	std::cout << "Bureaucrat with Default name created with lowest grade 150" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << "Bureaucrat named " << name << " created with grade " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy): _name(cpy.getName()), _grade(cpy.getGrade()) {
	std::cout << "Bureaucrat named " << cpy.getName() << " with grade ";
	std::cout << cpy.getGrade() << " copied" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat named " << this->_name << " with grade ";
	std::cout << this->_grade << " destructed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	this->_grade = rhs._grade;
	std::cout << "Bureaucrat named " << rhs.getName() << " with grade ";
	std::cout << rhs.getGrade() << " copied by assignement operator" << std::endl;
	return (*this);
}

std::string Bureaucrat::getName(void) const {
	return (this->_name);
}

int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()  {
	return((char*)"grade too high ! It must be between 1 and 150.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()  {
	return((char*)"grade too low ! It must be between 1 and 150.");
}

void	Bureaucrat::incrementGrade(void) {
	if (this->_grade <= 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else {
		this->_grade--;
		std::cout << this->_name << " has been graded to " << this->_grade << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void) {
	if (this->_grade >= 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		this->_grade++;
		std::cout << this->_name << " has been demoted to " << this->_grade << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &Bureaucrat) {
	o << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;;
	return (o);
}
