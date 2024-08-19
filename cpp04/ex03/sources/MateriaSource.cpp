/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:54:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/19 23:34:09 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource: Default Constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->saved_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &cpy) {
	std::cout << "MateriaSource: Copy constructor called" << std::endl;
	*this = cpy;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource: Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->saved_materias[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
	std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->saved_materias[i] != rhs.saved_materias[i])
			delete this->saved_materias[i];
		this->saved_materias[i] = NULL;
		if (rhs.saved_materias[i]) {
			this->saved_materias[i] =  rhs.saved_materias[i];
		}
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *MateriaSource) {
	for (int i = 0; i < 4; i++) {
		if (!this->saved_materias[i]) {
			this->saved_materias[i] = MateriaSource;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(const std::string &type) {
	AMateria	*new_materia;

	for (int i = 0; i < 4; i++) {
		if (this->saved_materias[i] && this->saved_materias[i]->getType() == type) {
			new_materia = this->saved_materias[i]->clone();
			return (new_materia);
		}
	}
	return (NULL);
}