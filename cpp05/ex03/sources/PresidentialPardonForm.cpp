/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:31:59 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 21:51:21 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", false, 25, 5), _target("Default target") {
	std::cout << "PresidentialPardonForm created with default target" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", false, 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm created with the target: " << this->_target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructed with the target: " << this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy): AForm(cpy), _target(cpy._target) {
	std::cout << "PresidentialPardonForm with target " << this->_target << " copied" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	(void)rhs;
	std::cout << "PresidentialPardonForm with target " << this->_target << " copied with assignment operator" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() >= this->getGradeToExe()) {
		std::cout << "can't execute the form because : ";
		throw Bureaucrat::GradeTooLowException();
	}
	else if (this->getSignature() == false)
		throw (AForm::NotSignedException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string	PresidentialPardonForm::getTarget(void) const {
	return (this->_target);
}
