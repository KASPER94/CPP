/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:31:19 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/12 20:36:47 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog: Default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &cpy): Animal(cpy){
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = cpy;
}

Dog::~Dog() {
	std::cout << "Dog: Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void	Dog::makeSound() {
	std::cout << "Bark" << std::endl;
}
