/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:31:19 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/17 22:30:33 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog: Default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain;
}

Dog::Dog(const Dog &cpy): Animal(cpy){
	std::cout << "Dog: Copy constructor called" << std::endl;
	this->_brain = NULL;
	*this = cpy;
}

Dog::~Dog() {
	std::cout << "Dog: Destructor called" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*rhs._brain);
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Bark" << std::endl;
}

void	Dog::setIdea(unsigned int i, std::string idea) {
	this->_brain->setIdea(i, idea);
}

void	Dog::getIdea() const {
	this->_brain->getIdea();
}
