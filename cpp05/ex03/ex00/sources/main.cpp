/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:18:29 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 15:03:25 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat Jimmy("jimmy", 2);
	Bureaucrat *Louis;
	Bureaucrat Antoine;

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
	try {
		Jimmy.incrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat Victor(Jimmy);
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
		Antoine.decrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << Antoine;
	std::cout << Jimmy;
	delete Louis;
	return (0);
}
