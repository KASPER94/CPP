/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:18:29 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 18:04:10 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	Bureaucrat Jimmy("jimmy", 5);
	Bureaucrat *Louis = new Bureaucrat("Louis", 150);
	Bureaucrat Victor(*Louis);

	std::cout << std::endl;
	AForm *f1 = new ShrubberyCreationForm("toilets");
	std::cout << *f1 << std::endl;
	ShrubberyCreationForm f2("garden");
	std::cout << f2 << std::endl;
	ShrubberyCreationForm f3("house");
	std::cout << f3 << std::endl;

	std::cout << std::endl;
	try {
		Louis->signForm(*f1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->beSigned(Jimmy);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->execute(Jimmy);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	// try {
	// 	Jimmy.incrementGrade();
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << Jimmy;
	// try {
	// 	Jimmy.signForm(f2);
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// try {
	// 	Jimmy.signForm(*f1);
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// try {
	// 	Jimmy.signForm(*f1);
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	return (0);
}
