/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:21:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/05 10:39:39 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name): _name(name), weapon(NULL)
{
	std::cout << name << " created without weapon " << std::endl;
}
HumanB::~HumanB()
{
	std::cout << this->_name << " deleted" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	std::cout << _name << " get weapon " << this->weapon->getType() << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->weapon->getType() << std::endl;
}