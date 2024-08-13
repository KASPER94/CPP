/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:31:19 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/12 20:37:10 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat: Default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &cpy): WrongAnimal(cpy) {
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	*this = cpy;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat: Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	std::cout << "WrongCat: Copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound() {
	std::cout << "Meow" << std::endl;
}
