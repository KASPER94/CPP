/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:11:43 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/11 14:55:44 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name") {
	std::cout << "DiamondTrap: Default Constructor called" << std::endl;
	this->_name = "default";
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_pts = 30;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name") {
	std::cout << "DiamondTrap: Default Constructor with name (" << name << ") called" <<std::endl;
	this->_name = name;
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_pts = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy): ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy) {
	std::cout << "DiamondTrap: Copy constructor with name (" << cpy._name << ") called" << std::endl; 
	*this = cpy;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap: Destructor for " << this->_name << " called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs) {
	std::cout << "DiamondTrap: copy assignment operator for " << rhs._name << " called" <<std::endl;
	this->_name = rhs._name;
	this->_hit_pts = rhs._hit_pts;
	this->_energy_pts = rhs._energy_pts;
	this->_attack_pts = rhs._attack_pts;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << this->_name << " and the ClapTrap name is " << this->ClapTrap::_name << std::endl;
}
