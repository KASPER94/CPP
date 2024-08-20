/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:49:37 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/20 16:39:35 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

std::string name;
AMateria	*inventory[4];

Character::Character() {
	this->name = "Default name";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name) {
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character &cpy) {
	*this = cpy;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}

Character &Character::operator=(const Character &rhs) {
	if (*this != rhs) {
		this->name = rhs.name;
		for (int i = 0; i < 4; i++) {
			if (this->inventory)
				delete this->inventory[i];
			this->inventory[i] = NULL;
			if (rhs.inventory[i])
				this->inventory[i] = rhs.inventory[i];
		}
	}
	return (*this);
}

const std::string &Character::getName() const {
	return (this->name);
}

void 		Character::equip(AMateria *m) {
	bool	inventory_full = false;

	for (int i = 0; i < 4; i++) {
		if (this->inventory[i]) {
			if (i == 3 && inventory_full == true) {
				std::cout << "Inventory's full, you might want to get rid of a materia before adding another one !" << std::endl;
				break ;
			}
		}
		if (!this->inventory[i]) {
			this->inventory[i] = m;
			break;
		}
	}
	if (inventory_full)
		return ;
}

void 		Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->inventory[idx]) {
		this->inventory[idx] = NULL;
	}
}

void 		Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && this->inventory[idx]) {
		this->inventory[idx]->use(target);
	}
}

AMateria	*Character::saveMateria(int idx) {
	if (idx >= 0 && idx < 4 && this->inventory[idx]) {
		return (this->inventory[idx]);
	}
	return (NULL);
}
