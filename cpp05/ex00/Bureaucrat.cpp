/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:20:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/23 11:13:49 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const std::string _name;
int	_grade;

Bureaucrat::Bureaucrat() : _mane(NULL), _grade(150) {

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {

}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) {
	*this = cpy;
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if ()
}

std::string Bureaucrat::getName() const {

}

int Bureaucrat::getGrade() const {

}

void	Bureaucrat::GradeTooHighException() const {

}

void	Bureaucrat::GradeTooLowException() const {

}

void	Bureaucrat::incrementGrade() {

}

void	Bureaucrat::decrementGrade() {

}
