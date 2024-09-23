/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:54:31 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 21:51:11 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &cpy) {
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = cpy;
}

Intern::~Intern() {
	std::cout << "Intern Deconstructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs) {
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

static AForm	*makePresident(const std::string target) {
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target) {
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string FormToCreate, const std::string TargetFromForm) {
	AForm *(*forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string form[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (FormToCreate == form[i])
		{
			std::cout << "\033[0;34mIntern creates " << FormToCreate << " with target: " << TargetFromForm << "\033[0m" << std::endl;
			return (forms[i](TargetFromForm));
		}
	}

	std::cout << "\033[0;31mI'm an Intern ! I can't create form I do not know... " << "\033[0m" << std::endl;
	return (NULL);
}
