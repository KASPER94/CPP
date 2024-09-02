/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:52:12 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/02 15:46:15 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() {
	std::cout << "Ice: Default Constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice(const std::string &type) {
	std::cout << "Ice: Default constructor with type " << type << " called" << std::endl;	
	this->type = type;
}

Ice::Ice(const Ice &cpy) : AMateria(cpy) {
	std::cout << "Ice: Copy constructor called" << std::endl;
	*this = cpy;
}

Ice::~Ice() {
	std::cout << "Ice: Destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &rhs) {
	std::cout << "Ice: Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

AMateria	*Ice::clone() const {
	std::cout << "Ice: Cloning Materia" << std::endl;	
	AMateria	*clone = new Ice(*this);
	return (clone);
}

void		Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
