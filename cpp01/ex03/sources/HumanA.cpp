/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:21:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/05 10:35:33 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), weapon(weapon)
{
	std::cout << name << " created with " << weapon.getType() << std::endl;
}
HumanA::~HumanA()
{
	std::cout << this->_name << " deleted" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->weapon.getType() << std::endl;
}