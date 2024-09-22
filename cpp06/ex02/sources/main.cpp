/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:05:50 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/22 23:55:14 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <unistd.h>
#include "Base.hpp"
#include "AClass.hpp"
#include "BClass.hpp"
#include "CClass.hpp"

Base	*generate(void) {
	int	rand = std::rand() % 3;

	if (rand == 0)
		return (new AClass);
	else if (rand == 1)
		return (new BClass);
	else
		return (new CClass);
}

void	identify(Base *p) {
	if (dynamic_cast<AClass*>(p))
		std::cout << "A Class" << std::endl;
	else if (dynamic_cast<BClass*>(p))
		std::cout << "B Class" << std::endl;
	else if (dynamic_cast<CClass*>(p))
		std::cout << "C Class" << std::endl;
}

void	identify(Base &p) {
	Base test;

	try {
		test = dynamic_cast<AClass&>(p);
		std::cout << "A Class" << std::endl;
	}
	catch (std::exception &e) {}
	try {
		test = dynamic_cast<BClass&>(p);
		std::cout << "B Class" << std::endl;
	}
	catch (std::exception &e) {}
		try {
		test = dynamic_cast<CClass&>(p);
		std::cout << "C Class" << std::endl;
	}
	catch (std::exception &e) {}
}

int	main(void) {
	Base *tmp;

	std::srand(time(NULL) * getpid() * getpid());
	std::cout << "identify with pointer 10 Classes between A, B and C denerated randomly" << std::endl;
	for (int i = 0; i < 10; i++) {
		tmp = generate();
		identify(tmp);
		delete tmp;
	}

	std::cout << "identify with reference 10 Classes between A, B and C denerated randomly" << std::endl;
	for (int i = 0; i < 10; i++) {
		tmp = generate();
		identify(*tmp);
		delete tmp;
	}
}