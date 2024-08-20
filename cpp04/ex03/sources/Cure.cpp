/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:52:12 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/20 18:45:02 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	std::cout << "Cure: Default Constructor called" << std::endl;
	this->type = "cure";
}

Cure::Cure(const std::string &type) {
	this->type = type;
}

Cure::Cure(const Ice &cpy) {
	*this = cpy;
}

Cure::~Cure() {

}

Cure &Cure::operator=(const Cure &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

Cure			*Cure::clone() const {
	AMateria	*clone = new Cure(*this);
	return (clone);
}

void		Cure::Cure(ICharacter &target) {
	std::cout << "* heals " << target.getName() << " 's wounds *" << std::endl;
}