/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:52:12 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/03 11:52:43 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {
	std::cout << "AMateria: Default constructor called" << std::endl;
	this->type = "Default Materia";
}

AMateria::AMateria(const std::string &type) : type(type) {
	std::cout << "AMateria: Default constructor with type " << type << " called" << std::endl;
}

AMateria::AMateria(const AMateria &cpy) {
	std::cout << "AMateria: Copy constructor called" << std::endl;
	*this = cpy;
}

AMateria::~AMateria() {
	std::cout << "AMateria: Destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs) {
	std::cout << "AMateria: Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return (*this);
}

std::string const 	&AMateria::getType() const {
	return (this->type);
}

void		AMateria::use(ICharacter &target) {
	std::cout << "* "  "use " << this->type << " on " << target.getName() << std::endl;
}
