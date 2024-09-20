/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:31:59 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/20 00:01:34 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", false, 72, 45),  _target(target) {
	std::cout << "RobotomyRequestForm Constructor with the target: " << this->_target << " called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm Destructor with the target: " << this->_target << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy): AForm(cpy), _target(cpy._target) {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	(void)rhs;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getSignature())
		throw AForm::FormAlreadySigned();
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
	else
		throw Bureaucrat::GradeTooLowException();
}

std::string	RobotomyRequestForm::getTarget() const {
	return (this->_target);
}
