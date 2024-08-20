/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:52:12 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/20 20:54:10 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() {
	std::cout << "Ice: Default Constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice(const std::string &type) {
	this->type = type;
}

Ice::Ice(const Ice &cpy) : AMateria(cpy) {
	*this = cpy;
}

Ice::~Ice() {

}

Ice &Ice::operator=(const Ice &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

AMateria	*Ice::clone() const {
	AMateria	*clone = new Ice(*this);
	return (clone);
}

void		Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
