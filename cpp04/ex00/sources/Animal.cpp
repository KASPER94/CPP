/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:31:19 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/12 20:29:13 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(std::string type): _type(type) {
	std::cout << "Animal: with type (" << type << ") constructor called" << std::endl;
}

Animal::Animal(const Animal &cpy): _type(cpy._type) {
	std::cout << "Animal: with type (" << cpy._type << ") Copy constructor called" << std::endl;
	*this = cpy;
}

Animal::~Animal() {
	std::cout << "Animal: with type (" << this->_type << ") Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
	std::cout << "Animal: with type (" << rhs._type << ") Copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void	Animal::makeSound() {
	std::cout << "Default animal, I don't make a sound" << std::endl;
}

std::string	Animal::getType() {
	return (this->_type);
}
