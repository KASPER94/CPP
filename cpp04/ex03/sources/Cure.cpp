/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:52:12 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/02 15:44:27 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() {
	std::cout << "Cure: Default Constructor called" << std::endl;
	this->type = "cure";
}

Cure::Cure(const std::string &type) {
	std::cout << "Cure: Default constructor with type " << type << " called" << std::endl;	
	this->type = type;
}

Cure::Cure(const Cure &cpy) : AMateria(cpy) {
	std::cout << "Cure: Copy constructor called" << std::endl;
	*this = cpy;
}

Cure::~Cure() {
	std::cout << "Cure: Destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &rhs) {
	std::cout << "Cure: Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

AMateria	*Cure::clone() const {
	std::cout << "Cure: Cloning Materia" << std::endl;	
	AMateria	*clone = new Cure(*this);
	return (clone);
}

void		Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << " 's wounds *" << std::endl;
}