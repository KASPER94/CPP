/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:52:12 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/20 18:37:10 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {
	this->type = "Default Materia";
}

AMateria::AMateria(const std::string &type) : type(type) {
	
}

AMateria::AMateria(const AMateria &cpy) {
	*this = cpy;
}

AMateria::~AMateria() {

}

AMateria &AMateria::operator=(const AMateria &rhs) {
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
