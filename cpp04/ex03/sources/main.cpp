/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:18:38 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/02 15:04:38 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void) {
	std::cout << "\e[0;36m------------------- Test 1 -------------------\e[0m" << std::endl;
	{
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter		*me = new Character("me");

		AMateria		*tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter		*bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		// Deleting inventory items if exist in me before assigning a copy of bob inventory check (valgrind);
		*(Character *)me = *(Character *)bob;

		IMateriaSource	*src_2 = new MateriaSource();
		// Deleting saved materias if exist in src before assigning a copy of src_2 inventory check (valgrind);
		*(MateriaSource *)src = *(MateriaSource *)src_2;

		delete bob;
		delete me;
		delete src;
		delete src_2;
	}
	std::cout << "\e[0;36m------------------- Test 2 -------------------\e[0m" << std::endl;
	{
		AMateria		*ground_materias[1024];
		unsigned int	nb_ground_materias = 0;

		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter		*me = new Character("me");

		AMateria		*tmp;
		std::cout << "\e[0;36msrc create materia(\"ice\")\e[0m" << std::endl;
		tmp = src->createMateria("ice");
		std::cout << "\e[0;36mme equip created materia (inventory : ice, none, none, none)\e[0m" << std::endl;
		me->equip(tmp);
		std::cout << "\e[0;36msrc create materia(\"cure\")\e[0m" << std::endl;
		tmp = src->createMateria("cure");
		std::cout << "\e[0;36mme equip created materia (inventory : ice, cure, none, none)\e[0m" << std::endl;
		me->equip(tmp);
		std::cout << "\e[0;36mme equip same created materia (inventory : ice, cure, none, none)\e[0m" << std::endl;
		me->equip(tmp);
		std::cout << "\e[0;36msaving materia before unequip (slot 1 : cure)\e[0m" << std::endl;
		ground_materias[nb_ground_materias++] = ((Character *)me)->saveMateria(1);
		std::cout << "\e[0;36mme unequip slot 1 (inventory: ice, none, none, none)\e[0m" << std::endl;
		me->unequip(1);
		std::cout << "\e[0;36msaving materia before unequip (slot 2 : none)\e[0m" << std::endl;
		ground_materias[nb_ground_materias++] = ((Character *)me)->saveMateria(2);
		std::cout << "\e[0;36mme unequip slot 2 (inventory: ice, none, none, none)\e[0m" << std::endl;
		me->unequip(2);
		std::cout << "\e[0;36msrc create materia(\"fire\")\e[0m" << std::endl;
		tmp = src->createMateria("fire");
		std::cout << "\e[0;36mme equip created materia (fire materia doesn't exist) (inventory : ice, none, none, none)\e[0m" << std::endl;
		me->equip(tmp);
		std::cout << "\e[0;36msrc create materia(\"ice\")\e[0m" << std::endl;
		tmp = src->createMateria("ice");
		std::cout << "\e[0;36mme equip created materia (inventory : ice, ice, none, none)\e[0m" << std::endl;
		me->equip(tmp);
		std::cout << "\e[0;36msrc create materia(\"cure\")\e[0m" << std::endl;
		tmp = src->createMateria("cure");
		std::cout << "\e[0;36mme equip created materia (inventory : ice, ice, cure, none)\e[0m" << std::endl;
		me->equip(tmp);
		std::cout << "\e[0;36msrc create materia(\"ice\")\e[0m" << std::endl;
		tmp = src->createMateria("ice");
		std::cout << "\e[0;36mme equip created materia (inventory : ice, ice, cure, ice)\e[0m" << std::endl;
		me->equip(tmp);
		std::cout << "\e[0;36msrc create materia(\"cure\")\e[0m" << std::endl;
		tmp = src->createMateria("cure");
		std::cout << "\e[0;36mme equip created materia (inventory : ice, ice, cure, ice)\e[0m" << std::endl;
		std::cout << "\e[0;36minventory is full\e[0m" << std::endl;
		me->equip(tmp);
		std::cout << "\e[0;36msaving created materia by src in ground_materias\e[0m" << std::endl;
		ground_materias[nb_ground_materias++] = tmp;

		ICharacter		*bob = new Character("bob");

		std::cout << "\e[0;36mme using slot 0 (ice) on bob\e[0m" << std::endl;
		me->use(0, *bob);
		std::cout << "\e[0;36mme using slot 3 (ice) on bob\e[0m" << std::endl;
		me->use(3, *bob);
		std::cout << "\e[0;36msaving materia before unequip (slot 1 : ice)\e[0m" << std::endl;
		ground_materias[nb_ground_materias++] = ((Character *)me)->saveMateria(1);
		std::cout << "\e[0;36mme unequip slot 1 (inventory: ice, none, cure, ice)\e[0m" << std::endl;
		me->unequip(1);
		std::cout << "\e[0;36mme using slot 1 (none) on bob\e[0m" << std::endl;
		me->use(1, *bob);

		std::cout << "\e[0;36mjohn: Character()\e[0m" << std::endl;
		Character		john;
		std::cout << "\e[0;36mjohn = *(Character *)me\e[0m" << std::endl;
		john = *((Character *)me);
		std::cout << "\e[0;36mjohn using slot 1 (none) on bob (inventory: ice, none, cure, ice)\e[0m" << std::endl;
		john.use(1, *bob);
		std::cout << "\e[0;36mjohn using slot 2 (cure) on bob (inventory: ice, none, cure, ice)\e[0m" << std::endl;
		john.use(2, *bob);

		std::cout << "\e[0;36msaving materia before unequip (john slot 2 : cure)\e[0m" << std::endl;
		ground_materias[nb_ground_materias++] = john.saveMateria(2);
		std::cout << "\e[0;36mjohn unequip slot 2 (inventory: ice, none, none, ice)\e[0m" << std::endl;
		john.unequip(2);
		std::cout << "\e[0;36mjohn unequip slot 2 (inventory: ice, none, none, ice)\e[0m" << std::endl;
		john.unequip(2);
		std::cout << "\e[0;36mme using slot 2 (cure) on me\e[0m" << std::endl;
		me->use(2, *me);

		std::cout << "\e[0;36mfred(john)\e[0m" << std::endl;
		Character		fred(john);
		std::cout << "\e[0;36mfred using slot 2 (none) on me (inventory: ice, none, none, ice)\e[0m" << std::endl;
		fred.use(2, *me);
		std::cout << "\e[0;36mfred using slot 3 (ice) on me (inventory: ice, none, none, ice)\e[0m" << std::endl;
		fred.use(3, *me);

		std::cout << "\e[0;36mDeleting ground materias\e[0m" << std::endl;
		for (unsigned int i = 0; i < nb_ground_materias; i++) {
			if (ground_materias[i])
				delete ground_materias[i];
		}
		delete bob;
		delete me;
		delete src;
	}
	return (0);
}
