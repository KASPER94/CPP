/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:20:58 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/13 18:51:51 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(const Brain &cpy) {
	std::cout << "Brain: Copy constructor called" << std::endl;
	*this = cpy;
}

Brain::~Brain() {
	std::cout << "Brain: Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs) {
	std::cout << "Brain: Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return	(*this);
}

void	Brain::setIdea(unsigned int i, std::string idea) {
	if (i >= 100)
		std::cerr << "This brain has a maximum ideas of 100 (index 99) !" << std::endl;
	else
		this->_ideas[i] = idea;
}

void	Brain::getIdea() {
	std::cout << "ideas: ";
	for (int i = 0; i < 100; i++)
		if (!this->_ideas[i].empty())
			std::cout << "idea " << i << "; " << this->_ideas[i] << std::endl;
}
