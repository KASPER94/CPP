/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:31:59 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 21:51:26 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", false, 72, 45),  _target("Default target") {
	std::cout << "RobotomyRequestForm created with the default target" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", false, 72, 45),  _target(target) {
	std::cout << "RobotomyRequestForm created with the target: " << this->_target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm descruted with the target: " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy): AForm(cpy), _target(cpy._target) {
	std::cout << "RobotomyRequestForm with target " << this->_target << " copied" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	(void)rhs;
	std::cout << "RobotomyRequestForm with target " << this->_target << " copied with assignment operator" << std::endl;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getSignature())
		throw AForm::NotSignedException();
	if (executor.getGrade() <= this->getGradeToExe()) {
		for (int i = 0; i < 30; i++) {
			if (i % 2) {
				std::cout << "BzzzzRzzRrrrzzZZzzzz." << std::endl;
				std::cout << this->getTarget() << " has been robotomized." << std::endl;
			} else {
				std::cout << "Robotomy failed." << std::endl;
			}
		}
	}
	else {
		std::cout << "can't execute the form because : ";
		throw Bureaucrat::GradeTooLowException();
	}
}

std::string	RobotomyRequestForm::getTarget(void) const {
	return (this->_target);
}
