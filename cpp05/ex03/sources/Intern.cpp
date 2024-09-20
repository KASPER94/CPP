/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:54:31 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/20 10:39:40 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &cpy)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = cpy;
}

Intern::~Intern()
{
	std::cout << "Intern Deconstructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string FormToCreate, const std::string TargetFromForm)
{
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (FormToCreate == forms[i])
		{
			std::cout << "Intern creates " << FormToCreate << " with target: " << TargetFromForm << std::endl;
			return (all_forms[i](TargetFromForm));
		}
	}

	std::cout << "\033[0;31mI'm an Intern ! I can't create form I do not know... " << "\033[0m" << std::endl;
	return (NULL);
}

