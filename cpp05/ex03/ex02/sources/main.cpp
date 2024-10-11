/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:18:29 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 18:37:33 by skapersk         ###   ########.fr       */
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
	std::cout << "Shrubbery Tests" << std::endl;
	AForm *f1 = new ShrubberyCreationForm("toilets");
	std::cout << *f1 << std::endl;
	ShrubberyCreationForm f2("garden");
	std::cout << f2 << std::endl;

	try {
		Louis->signForm(*f1);
	}
	catch (std::exception &e) {
		std::cout <<"Can't sign Form because : ";
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
	delete f1;

	std::cout << std::endl;
	std::cout << "Robotomy Request Tests" << std::endl;
	f1 = new RobotomyRequestForm(Jimmy.getName());
	std::cout << *f1 << std::endl;
	RobotomyRequestForm f3("Juan");
	std::cout << f3 << std::endl;

	for (; Louis->getGrade() > 73; ) {
		Louis->incrementGrade();
	}
	try {
		f1->beSigned(*Louis);
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
	Louis->incrementGrade();
	try {
		f1->beSigned(*Louis);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->beSigned(*Louis);
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
	delete f1;

	std::cout << std::endl;
	std::cout << "Presidential Pardon Tests" << std::endl;
	f1 = new PresidentialPardonForm(Jimmy.getName());
	std::cout << *f1 << std::endl;
	PresidentialPardonForm f4(*dynamic_cast<PresidentialPardonForm*>(f1));
	std::cout << f4 << std::endl;

	for (; Louis->getGrade() > 25; ) {
		Louis->incrementGrade();
	}
	try {
		Louis->signForm(*f1);
	}
	catch (std::exception &e) {
		std::cout <<"Can't sign Form because : ";
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	Louis->incrementGrade();
	try {
		f1->beSigned(*Louis);
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

	delete Louis;
	delete f1;
	return (0);
}
