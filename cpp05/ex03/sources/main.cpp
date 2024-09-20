/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:18:29 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/20 11:42:35 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
// #include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat Jimmy("jimmy", 2);
	Bureaucrat *Lou;
	Bureaucrat Cam;

	Intern someRandomIntern;
	AForm* Forn1;
	AForm* Forn2;
	AForm* Forn3;
	Forn1 = someRandomIntern.makeForm("robotomy request", "Red");
	Forn1 = someRandomIntern.makeForm("RobotomyRequestForm", "Red");
	Forn2 = someRandomIntern.makeForm("PresidentialPardonForm", "Bond");
	Forn3 = someRandomIntern.makeForm("ShrubberyCreationForm", "M");
	((ShrubberyCreationForm*)Forn3)->execute(Jimmy);
	Lou = new Bureaucrat("Lou", 150);
	try {
		Jimmy.incrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Jimmy.incrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Lou->decrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Cam.decrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << Cam;
	delete Lou;
	delete Forn1;
	delete Forn2;
	delete Forn3;
	return (0);
}
