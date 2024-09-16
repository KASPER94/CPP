/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:18:29 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/16 17:50:02 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat Jimmy("jimmy", 2);
	Bureaucrat *Lou;
	Bureaucrat Cam;

	try {
		Lou = new Bureaucrat("Lou", 158);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Lou = new Bureaucrat("Lou", 150);
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
		Jimmy.incrementGrade();
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
	std::cout << Jimmy;
	delete Lou;
	return (0);
}
