/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:11:43 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/11 11:35:22 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "FragTrap: Default Constructor called" << std::endl;
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_pts = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap: Default Constructor with name (" << name << ") called" <<std::endl;
	this->_name = name;
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_pts = 30;
}

FragTrap::FragTrap(const FragTrap &cpy): ClapTrap(cpy) {
	std::cout << "FragTrap: Copy constructor with name (" << cpy._name << ") called" << std::endl; 
	*this = cpy;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap: Destructor for " << this->_name << " called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs) {
	std::cout << "FragTrap: copy assignment operator for " << rhs._name << " called" <<std::endl;
	this->_name = rhs._name;
	this->_hit_pts = rhs._hit_pts;
	this->_energy_pts = rhs._energy_pts;
	this->_attack_pts = rhs._attack_pts;
	return *this;
}

void	FragTrap::attack(const std::string &target) {
	if (this->_hit_pts > 0 && this->_energy_pts > 0) {
		this->_energy_pts--;
		std::cout << "FragTrap: " << this->_name << " attacks " << target
			<< " causing " << this->_attack_pts << " points of damage !" << std::endl;
	}
	else if (this->_energy_pts == 0 && this->_hit_pts == 0) {
		std::cout << "FragTrap : " << this->_name << " can't attack, its health and energy are too low" << std::endl;
	}
	else if (this->_energy_pts > 0) {
		std::cout << "FragTrap : " << this->_name << " can't attack, its health is too low" << std::endl;
	}
	else {
		std::cout << "FragTrap : " << this->_name << " can't attack, its energy is too low" << std::endl;
	}
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " requests a high five !" << std::endl;
}
