/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:18:29 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 15:41:10 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat Jimmy("jimmy", 5);
	Bureaucrat *Louis;
	Bureaucrat Victor(Jimmy);

	try {
		Louis = new Bureaucrat("Louis", 158);
	}
	catch (std::exception &e) {
		std::cout <<"Can't create Bureaucrat because : ";
		std::cerr << e.what() << std::endl;
	}
	try {
		Louis = new Bureaucrat("Louis", 150);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	Bureaucrat *Antoine = Louis;

	std::cout << std::endl;
	Form *f1 = new Form();
	std::cout << *f1 << std::endl;
	Form f2("contract 1", 4, 55);
	std::cout << f2 << std::endl;

	try {
		Form f3("contract 2", 10, 155);
	}
	catch (std::exception &e) {
		std::cout <<"Can't create Form because : ";
		std::cerr << e.what() << std::endl;
	}
	try {
		Form f3("contract 2", 0, 150);
	}
	catch (std::exception &e) {
		std::cout <<"Can't create Form because : ";
		std::cerr << e.what() << std::endl;
	}
	try {
		Form f3("contract 2", 10, 150);
	}
	catch (std::exception &e) {
		std::cout <<"Can't create Form because : ";
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try {
		Jimmy.signForm(f2);
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
	std::cout << Jimmy;
	try {
		Jimmy.signForm(f2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Jimmy.signForm(*f1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Jimmy.signForm(*f1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << *Antoine;
	delete Louis;
	delete f1;
	return (0);
}
