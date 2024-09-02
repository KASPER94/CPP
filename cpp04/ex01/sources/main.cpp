/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:18:38 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/02 13:31:17 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal		*Animals[100];

	for (int i = 0; i < 5; i++) {
		Animals[i] = new Dog;
	}
	for (int i = 5; i < 10; i++) {
		Animals[i] = new Cat;
	}
	Cat Kitten(*(Cat *)Animals[9]);
	for (int i = 0; i < 5; i++) {
		Dog &Doggy(*(Dog *)Animals[i]);
		std::cout << "\e[0;32mAnimals[" << i << "] : (type: " << Doggy.getType() << ")\e[0m" << std::endl;
		Doggy.makeSound();
		Doggy.setIdea(i, "I'm hungry ! where's my bone ?");
		std::cout << "\e[0;32mAnimals[" << i << "] : (type: ";
		Doggy.getIdea();
		std::cout << ")\e[0m" << std::endl;
	}
	for (int j = 0; j < 101; j++) {
			Kitten.setIdea(j, "I'm hungry ! Feed me ?");
	}
	std::cout << "\e[0;36mKitten ";
	Kitten.getIdea();
	std::cout << ")\e[0m" << std::endl;
	for (int i = 5; i < 10; i++) {
		Cat &Kitty(*(Cat *)Animals[i]);
		std::cout << "\e[0;34mAnimals[" << i << "] : (type: " << Kitty.getType() << ")\e[0m" << std::endl;
		Kitty.makeSound();
		std::cout << "\e[0;34mAnimals[" << i << "] : (type: ";
		Kitty.getIdea();
		std::cout << ")\e[0m" << std::endl;
	}

	for (int i = 0; i < 10; i++) {
		delete Animals[i];
	}
	return (0);

}
