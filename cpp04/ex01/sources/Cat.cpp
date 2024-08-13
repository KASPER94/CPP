/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:31:19 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/13 18:48:00 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat: Default constructor called" << std::endl;
	this->_brain = new Brain;
	this->_type = "Cat";
}

Cat::Cat(const Cat &cpy): Animal(cpy) {
	std::cout << "Cat: Copy constructor called" << std::endl;
	this->_brain = NULL;
	*this = cpy;
}

Cat::~Cat() {
	std::cout << "Cat: Destructor called" << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(const Cat &rhs) {
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*rhs._brain);
	return (*this);
}

void	Cat::makeSound() {
	std::cout << "Meow" << std::endl;
}

void	Cat::setIdea(unsigned int i, std::string idea) {
	this->_brain->setIdea(i, idea);
}

void	Cat::getIdea() {
	this->_brain->getIdea();
}
