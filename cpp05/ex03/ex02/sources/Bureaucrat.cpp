/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:20:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 21:52:15 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

Bureaucrat::~Bureaucrat() {
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
	return((char*)"Bureaucrat's grade too high !");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()  {
	return((char*)"Bureaucrat's grade too low !");
}

void	Bureaucrat::incrementGrade(void) {
	if (this->_grade == 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else {
		std::cout << "congrats you've been graded !" << std::endl;
		this->_grade--;
	}
}

void	Bureaucrat::decrementGrade(void) {
	if (this->_grade == 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		this->_grade++;
		std::cout << this->_name << " has been demoted to " << this->_grade << std::endl;
	}
}

void	Bureaucrat::signForm(AForm &AForm) {
	try {
		AForm.beSigned(*this);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &Bureaucrat) {
	o << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;;
	return (o);
}
