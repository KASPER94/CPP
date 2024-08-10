/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:11:08 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/10 17:07:38 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main() {
	ScavTrap a("Mrs ScavTrap");
	ScavTrap b(a);
	ScavTrap c("Mr ScavTrap");
	ScavTrap d = c;

	std::cout << "a: ";
	a.attack("Agent 1");
	std::cout << "b: ";
	a.attack("Agent 2");
	std::cout << "c: ";
	a.attack("Agent 1");
	std::cout << "d: ";
	a.attack("Agent 2");
	
	std::cout << "a: ";
	a.takeDamage(3);
	std::cout << "b: ";
	b.takeDamage(5);
	std::cout << "c: ";
	c.takeDamage(7);
	std::cout << "d: ";
	d.takeDamage(12);

	std::cout << "a: ";
	a.attack("Agent 1");	
	std::cout << "a: ";
	a.attack("Agent 1");
	std::cout << "a: ";
	a.attack("Agent 1");
	std::cout << "a: ";
	a.attack("Agent 1");
	std::cout << "b: ";
	a.attack("Agent 2");
	std::cout << "c: ";
	a.attack("Agent 1");
	std::cout << "d: ";
	a.attack("Agent 2");

	std::cout << "a: ";
	a.takeDamage(5);
	std::cout << "a: ";
	a.beRepaired(4);
	std::cout << "a: ";
	a.takeDamage(5);
	std::cout << "a: ";
	a.beRepaired(8);
	std::cout << "a: ";
	a.takeDamage(5);
	std::cout << "a: ";
	a.beRepaired(4);
	std::cout << "a: ";
	a.takeDamage(5);
	std::cout << "a: ";
	a.beRepaired(4);
	std::cout << "a: ";
	a.takeDamage(5);
	std::cout << "a: ";
	a.beRepaired(4);
	std::cout << "a: ";
	a.takeDamage(5);
	std::cout << "a: ";
	a.beRepaired(4);
	std::cout << "a: ";
	a.beRepaired(4);
	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "a: ";
	a.takeDamage(5);
	std::cout << "a: ";
	a.attack("some random guy");

	return (0);
}