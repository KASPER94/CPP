/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:11:43 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/10 13:30:24 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hit_pts(100), _energy_pts(50), _attack_pts(20) {
	std::cout << "ClapTrap: Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_pts(100), _energy_pts(50), _attack_pts(20) {
	std::cout << "ClapTrap: Default Constructor with name (" << name << ") called" <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy) {
	std::cout << "ClapTrap: Copy constructor with name (" << cpy._name << ") called" << std::endl; 
	*this = cpy;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap: Destructor for " << this->_name << " called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs) {
	std::cout << "ClapTrap: copy assignment operator for " << rhs._name << " called" <<std::endl;
	this->_name = rhs._name;
	this->_hit_pts = rhs._hit_pts;
	this->_energy_pts = rhs._energy_pts;
	this->_attack_pts = rhs._attack_pts;
	return *this;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_hit_pts > 0 && this->_energy_pts > 0) {
		this->_energy_pts--;
		std::cout << "ClapTrap: " << this->_name << " attacks " << target
			<< " causing " << this->_attack_pts << " points of damage !" << std::endl;
	}
	else if (this->_energy_pts == 0 && this->_hit_pts == 0) {
		std::cout << "ClapTrap : " << this->_name << " can't attack, its health and energy are too low" << std::endl;
	}
	else if (this->_energy_pts > 0) {
		std::cout << "ClapTrap : " << this->_name << " can't attack, its health is too low" << std::endl;
	}
	else {
		std::cout << "ClapTrap : " << this->_name << " can't attack, its energy is too low" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_pts < amount) {
		this->_hit_pts = 0;
	}
	else
		this->_hit_pts -= amount;
	std::cout << "ClapTrap: " << this->_name << " took " << amount << " points of damage !"
		<< " it remains : " << this->_hit_pts << std::endl;
		
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy_pts > 0 && this->_hit_pts > 0) {
		this->_energy_pts--;
		this->_hit_pts += amount;
		std::cout << "ClapTrap : " << this->_name << " repqirs itself (" << amount
			<< "), new hit points: " << this->_hit_pts << std::endl;
	}
	else if (this->_energy_pts == 0 && this->_hit_pts == 0) {
		std::cout << "ClapTrap : " << this->_name << " can't repair itself, its health and energy are too low" << std::endl;
	}
	else if (this->_energy_pts > 0) {
		std::cout << "ClapTrap : " << this->_name << " can't repair itself, its health is too low" << std::endl;
	}
	else {
		std::cout << "ClapTrap : " << this->_name << " can't repair itself, its energy is too low" << std::endl;
	}
}
