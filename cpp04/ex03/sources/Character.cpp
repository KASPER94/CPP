/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:49:37 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/04 00:15:33 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): name("Default name") {
	std::cout << "Character: Default constructor called" << std::endl;	
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name): name(name) {
	std::cout << "Character: Default constructor with name " << name << " called" << std::endl;	
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character &cpy) {
	std::cout << "Character: Copy constructor of " << cpy.getName() << "called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
	*this = cpy;
}

Character::~Character() {
	std::cout << "Character: Destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
		}
	}
}

Character &Character::operator=(const Character &rhs) {
    std::cout << "Character: Copy assignment operator of " << rhs.getName() << " called" << std::endl;
    if (this != &rhs) {
        this->name = rhs.getName();
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i] != NULL) {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
            if (rhs.inventory[i]) {
                this->inventory[i] = rhs.inventory[i]->clone();
            }
        }
    }
    return (*this);
}


const std::string &Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria *m) {
    bool inventory_full = true;

	if (m == NULL)
		return ;
    for (int i = 0; i < 4; i++) {
        if (!this->inventory[i]) {
            inventory_full = false;
            break ;
        }
    }
    if (inventory_full == true) {
        std::cout << "Inventory's full, you might want to get rid of a materia before adding another one !" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++) {
        if (!this->inventory[i]) {
            this->inventory[i] = m;
            break ;
        }
    }
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

AMateria* Character::saveMateria(int idx) {
    if (idx >= 0 && idx < 4 && this->inventory[idx]) {
        return this->inventory[idx];
    }
    return NULL; 
}
