/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:11:43 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/09 15:44:14 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hit_pts(0), _energy_pts(0), _attack_pts(0) {
	std::cout << "ClapTrap: Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_pts(10), _energy_pts(10), _attack_pts(0) {
	std::cout << "ClapTrap: Default Constructor with name (" << name << ") called" <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy): {
	std::cout << "ClapTrap: Copy constructor with name (" << cpy.name << ") called" << std::endl; 
	*this = &cpy;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap: Destructor for " << this->_name << " called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs) {
	std::cout << "ClapTrap: copy assignment operator for " << rhs.name << " called" <<std::endl;
	return rhs;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_hit_pts > 0 && this->_energy_pts > 0) {
		this->_energy_pts--;
		std::cout << "ClapTrap: " << this->_name << " attacks " << target
			<< " causing " << this->_attack_pts << " points of damage !" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amout) {
	if (this->_hit_pts < amout)
		
}

void	ClapTrap::beRepaired(unsigned int amout) {

}
