/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:31:19 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/17 22:30:45 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
	std::cout << "WrongAnimal: with type (" << type << ") constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy): _type(cpy._type) {
	std::cout << "WrongAnimal: with type (" << cpy._type << ") Copy constructor called" << std::endl;
	*this = cpy;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: with type (" << this->_type << ") Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	std::cout << "WrongAnimal: with type (" << rhs._type << ") Copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void	WrongAnimal::makeSound() const {
	std::cout << "Default WrongAnimal, I don't make a sound" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return (this->_type);
}
