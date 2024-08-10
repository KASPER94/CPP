/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:11:43 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/10 17:06:49 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap: Default Constructor called" << std::endl;
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_pts = 20;
	this->_gateKeeperMode = false;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "ScavTrap: Default Constructor with name (" << name << ") called" <<std::endl;
	this->_name = name;
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_pts = 20;
	this->_gateKeeperMode = false;
}

ScavTrap::ScavTrap(const ScavTrap &cpy): ClapTrap(cpy) {
	std::cout << "ScavTrap: Copy constructor with name (" << cpy._name << ") called" << std::endl; 
	*this = cpy;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: Destructor for " << this->_name << " called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs) {
	std::cout << "ScavTrap: copy assignment operator for " << rhs._name << " called" <<std::endl;
	this->_name = rhs._name;
	this->_hit_pts = rhs._hit_pts;
	this->_energy_pts = rhs._energy_pts;
	this->_attack_pts = rhs._attack_pts;
	this->_gateKeeperMode = rhs._gateKeeperMode;
	return *this;
}

void	ScavTrap::attack(const std::string &target) {
	if (this->_hit_pts > 0 && this->_energy_pts > 0) {
		this->_energy_pts--;
		std::cout << "ScavTrap: " << this->_name << " attacks " << target
			<< " causing " << this->_attack_pts << " points of damage !" << std::endl;
	}
	else if (this->_energy_pts == 0 && this->_hit_pts == 0) {
		std::cout << "ScavTrap : " << this->_name << " can't attack, its health and energy are too low" << std::endl;
	}
	else if (this->_energy_pts > 0) {
		std::cout << "ScavTrap : " << this->_name << " can't attack, its health is too low" << std::endl;
	}
	else {
		std::cout << "ScavTrap : " << this->_name << " can't attack, its energy is too low" << std::endl;
	}
}

void	ScavTrap::guardGate(void) {
	if (this->_energy_pts > 0 && this->_hit_pts > 0 && !this->_gateKeeperMode) {
		this->_energy_pts--;
		this->_gateKeeperMode = true;
		std::cout << "ScavTrap " << this->_name << " is now in gate keeper mode" << std::endl;
	}
	else if (this->_energy_pts > 0 && this->_hit_pts >0 && this->_gateKeeperMode) {
		std::cout << "ScavTrap : " << this->_name << " is already in gate keeper mode"
			<< ", its health and energy are too low (" << this->_hit_pts
			<< " hit point; " << this->_energy_pts << " energy point)" << std::endl;

	}
	else if (this->_energy_pts == 0 && this->_hit_pts == 0) {
		std::cout << "ScavTrap : " << this->_name << " can't switch to gate keeper mode, its health and energy are too low" << std::endl;
	}
	else if (this->_energy_pts > 0) {
		std::cout << "ScavTrap : " << this->_name << " can't switch to gate keeper mode, its health is too low" << std::endl;
	}
	else {
		std::cout << "ScavTrap : " << this->_name << " can't switch to gate keeper mode, its energy is too low" << std::endl;
	}
}
