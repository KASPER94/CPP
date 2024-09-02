/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:11:08 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/11 11:36:17 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	ScavTrap a("Mrs ScavTrap");
	ScavTrap b(a);
	ScavTrap c("Mr ScavTrap");
	ScavTrap d = c;
	FragTrap e("Mr FragTrap");
	FragTrap f(e);
	FragTrap g("Mrs FragTrap");
	FragTrap h = g;


	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "b: ";
	b.attack("some random guy");
	std::cout << "c: ";
	c.attack("some random guy");
	std::cout << "d: ";
	d.attack("some random guy");

	std::cout << "a: ";
	a.takeDamage(30);
	std::cout << "b: ";
	b.takeDamage(50);
	std::cout << "c: ";
	c.takeDamage(70);
	std::cout << "d: ";
	d.takeDamage(120);

	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "b: ";
	b.attack("some random guy");
	std::cout << "c: ";
	c.attack("some random guy");
	std::cout << "d: ";
	d.attack("some random guy");

	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(80);
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.attack("some random guy");
	for (int i = 0; i < 40; i++) {
		std::cout << "a: ";
		a.attack("some random guy");
	}
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(40);

	std::cout << "a: ";
	a.guardGate();
	std::cout << "b: ";
	b.guardGate();
	std::cout << "b: ";
	b.guardGate();
	std::cout << "b: ";
	b.guardGate();


	std::cout << "e: ";
	e.attack("some random guy");
	std::cout << "f: ";
	f.attack("some random guy");
	std::cout << "g: ";
	g.attack("some random guy");
	std::cout << "h: ";
	h.attack("some random guy");

	std::cout << "e: ";
	e.takeDamage(30);
	std::cout << "f: ";
	f.takeDamage(50);
	std::cout << "g: ";
	g.takeDamage(70);
	std::cout << "h: ";
	h.takeDamage(120);

	std::cout << "e: ";
	e.attack("some random guy");
	std::cout << "e: ";
	e.attack("some random guy");
	std::cout << "e: ";
	e.attack("some random guy");
	std::cout << "e: ";
	e.attack("some random guy");
	std::cout << "f: ";
	f.attack("some random guy");
	std::cout << "g: ";
	g.attack("some random guy");
	std::cout << "h: ";
	h.attack("some random guy");

	std::cout << "e: ";
	e.takeDamage(50);
	std::cout << "e: ";
	e.beRepaired(40);
	std::cout << "e: ";
	e.takeDamage(50);
	std::cout << "e: ";
	e.beRepaired(80);
	std::cout << "e: ";
	e.takeDamage(50);
	std::cout << "e: ";
	e.beRepaired(40);
	std::cout << "e: ";
	e.takeDamage(50);
	std::cout << "e: ";
	e.beRepaired(40);
	std::cout << "e: ";
	e.takeDamage(50);
	std::cout << "e: ";
	e.beRepaired(40);
	std::cout << "e: ";
	e.takeDamage(50);
	std::cout << "e: ";
	e.beRepaired(40);
	std::cout << "e: ";
	e.beRepaired(40);
	std::cout << "e: ";
	e.attack("some random guy");
	std::cout << "e: ";
	e.takeDamage(50);
	std::cout << "e: ";
	e.attack("some random guy");
	for (int i = 0; i < 90; i++) {
		std::cout << "e: ";
		e.attack("some random guy");
	}
	std::cout << "e: ";
	e.beRepaired(40);
	std::cout << "e: ";
	e.takeDamage(50);
	std::cout << "e: ";
	e.beRepaired(40);

	std::cout << "e: ";
	e.highFivesGuys();
	std::cout << "f: ";
	f.highFivesGuys();
	std::cout << "f: ";
	f.takeDamage(123);
	std::cout << "f: ";
	f.highFivesGuys();

	return(0);
}