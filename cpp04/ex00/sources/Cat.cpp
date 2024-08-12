/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:31:19 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/12 20:36:36 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat: Default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &cpy): Animal(cpy) {
	std::cout << "Cat: Copy constructor called" << std::endl;
	*this = cpy;
}

Cat::~Cat() {
	std::cout << "Cat: Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void	Cat::makeSound() {
	std::cout << "Meow" << std::endl;
}
