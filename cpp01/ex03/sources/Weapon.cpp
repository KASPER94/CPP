/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:21:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/05 10:42:01 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
	std::cout << "Weapon created with type : " << type << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon with type : " << this->_type << " deleted" << std::endl; 
}

const std::string &Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	std::cout << "Weapon with type : " << this->_type << " change in : " << type << std::endl;
}