/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:52:12 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/20 16:41:35 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
std::string type;

AMateria::AMateria() {

}

AMateria::AMateria(std::string const &type) {

}

AMateria::AMateria(const AMateria &cpy) {

}

AMateria::~AMateria() {

}

AMateria &AMateria::operator=(const AMateria &rhs) {

}

std::string const 	&AMateria::getType() const {

}

virtual AMateria	*AMateria::clone() const {

}

virtual void		AMateria::use(ICharacter &target) {
	
}
