/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:18:29 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 21:47:01 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
	Intern someRandomIntern;
	AForm* Form1;
	AForm* Form2;
	AForm* Form3;
	Form1 = someRandomIntern.makeForm("robotomy request", "Red");
	Form1 = someRandomIntern.makeForm("RobotomyRequestForm", "Red");
	Form2 = someRandomIntern.makeForm("PresidentialPardonForm", "Bond");
	Form3 = someRandomIntern.makeForm("ShrubberyCreationForm", "M");
	Bureaucrat Jimmy("jimmy", 5);
	Bureaucrat *Louis = new Bureaucrat("Louis", 150);
	Bureaucrat Victor(*Louis);

	std::cout << std::endl;
	std::cout << "Shrubbery Tests" << std::endl;
	std::cout << *Form3 << std::endl;

	try {
		Louis->signForm(*Form3);
	}
	catch (std::exception &e) {
		std::cout <<"Can't sign Form because : ";
		std::cerr << e.what() << std::endl;
	}
	try {
		Form3->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form3->beSigned(Jimmy);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form3->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form3->execute(Jimmy);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete Form3;

	std::cout << std::endl;
	std::cout << "Robotomy Request Tests" << std::endl;
	std::cout << *Form1 << std::endl;

	for (; Louis->getGrade() > 73; ) {
		Louis->incrementGrade();
	}
	try {
		Form1->beSigned(*Louis);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form1->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	Louis->incrementGrade();
	try {
		Form1->beSigned(*Louis);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form1->beSigned(*Louis);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form1->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form1->execute(Jimmy);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete Form1;

	std::cout << std::endl;
	std::cout << "Presidential Pardon Tests" << std::endl;
	std::cout << *Form2 << std::endl;

	for (; Louis->getGrade() > 25; ) {
		Louis->incrementGrade();
	}
	try {
		Louis->signForm(*Form2);
	}
	catch (std::exception &e) {
		std::cout <<"Can't sign Form because : ";
		std::cerr << e.what() << std::endl;
	}
	try {
		Form2->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	Louis->incrementGrade();
	try {
		Form2->beSigned(*Louis);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form2->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form2->execute(Jimmy);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	delete Louis;
	delete Form2;
	return (0);
}
