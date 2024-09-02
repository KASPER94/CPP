/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:18:38 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/02 13:52:26 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int	main(void)
{
	std::cout << "-------------------1st test : Default-------------------" << std::endl;
	Dog	*doggy = new Dog;
	Cat	*kitty = new Cat;

	std::cout << "doggy : (type: " << doggy->getType() << ")" << std::endl;
	doggy->makeSound();
	std::cout << "kitty : (type: " << kitty->getType() << ")" << std::endl;
	kitty->makeSound();
	delete kitty;
	delete doggy;
	std::cout << std::endl;

	std::cout << "-------------------2nd test : Array -------------------" << std::endl;
	Animal	*animals[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << std::endl;
		std::cout << "Animal type: " << animals[i]->getType() << " makes : ";
		animals[i]->makeSound();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
	std::cout << std::endl;

	std::cout << "-------------------3rd test : Ideas -------------------" << std::endl;
	Dog	*doug = new Dog;

	std::cout << "\e[0;32mdoug : (type: " << doug->getType() << ")" << std::endl;
	std::cout << "Setting ideas...\e[0m" << std::endl;
	doug->setIdea(0, "I'm hungry...");
	doug->setIdea(12, "Where is my bone ?");
	std::cout << "\e[0;32mdoug : (type: " << doug->getType() << ")\e[0m" << std::endl;
	doug->getIdea();
	Dog puppy = *doug;
	std::cout << "\e[0;32mpuppy : (type: " << puppy.getType() << ")\e[0m" << std::endl;
	puppy.getIdea();
	Dog pup(puppy);
	std::cout << "\e[0;32mpup : (type: " << pup.getType() << ")\e[0m" << std::endl;
	pup.getIdea();
	std::cout << "\e[0;32mdoug : (type: " << doug->getType() << ")" << std::endl;
	std::cout << "Setting ideas...\e[0m" << std::endl;
	doug->setIdea(0, "I'm not hungry anymore...");
	doug->setIdea(12, "I juste found my bone !");
	std::cout << "\e[0;32mdoug : (type: " << doug->getType() << ")\e[0m" << std::endl;
	doug->getIdea();
	std::cout << "\e[0;32mpuppy : (type: " << puppy.getType() << ")\e[0m" << std::endl;
	puppy.getIdea();
	std::cout << "\e[0;32mpup : (type: " << pup.getType() << ")\e[0m" << std::endl;
	pup.getIdea();
	std::cout << "\e[0;32mpuppy : (type: " << puppy.getType() << ")" << std::endl;
	std::cout << "Setting ideas...\e[0m" << std::endl;
	puppy.setIdea(0, "I'm more hungry than ever !");
	puppy.setIdea(12, "Even if I ate my bone !");
	std::cout << "\e[0;32mdoug: (type: " << doug->getType() << ")\e[0m" << std::endl;
	doug->getIdea();
	std::cout << "\e[0;32mpuppy : (type: " << puppy.getType() << ")\e[0m" << std::endl;
	puppy.getIdea();
	std::cout << "\e[0;32mpup : (type: " << pup.getType() << ")\e[0m" << std::endl;
	pup.getIdea();
	delete doug;

	Cat	*kitten = new Cat;
	std::cout << "\e[0;34mkitten : (type: " << kitten->getType() << ")" << std::endl;
	std::cout << "Setting ideas...\e[0m" << std::endl;
	kitten->setIdea(25, "I'm tired...");
	kitten->setIdea(13, "What the f*ck am I eating ? Is it my tail ?");
	std::cout << "\e[0;34mkitten : (type: " << kitten->getType() << ")\e[0m" << std::endl;
	kitten->getIdea();
	Cat garfield = *kitten;
	std::cout << "\e[0;34mgarfield : (type: " << garfield.getType() << ")\e[0m" << std::endl;
	garfield.getIdea();
	Cat kits(garfield);
	std::cout << "\e[0;34mkits : (type: " << kits.getType() << ")\e[0m" << std::endl;
	kits.getIdea();
	std::cout << "\e[0;34mgarfield : (type: " << kitten->getType() << ")" << std::endl;
	std::cout << "Setting ideas...\e[0m" << std::endl;
	kitten->setIdea(25, "I'm tiiiiirrreeeeeeeeed...");
	kitten->setIdea(13, "I'm so stupid, this is my tail... I'm tired tho.");
	std::cout << "\e[0;34mkitten : (type: " << kitten->getType() << ")\e[0m" << std::endl;
	kitten->getIdea();
	std::cout << "\e[0;34mgarfield : (type: " << garfield.getType() << ")\e[0m" << std::endl;
	garfield.getIdea();
	std::cout << "\e[0;34mkits : (type: " << kits.getType() << ")\e[0m" << std::endl;
	kits.getIdea();
	std::cout << "\e[0;34mgarfield : (type: " << garfield.getType() << ")" << std::endl;
	std::cout << "Setting ideas...\e[0m" << std::endl;
	garfield.setIdea(25, "I'm tir.. zzzZZZzzz");
	garfield.setIdea(13, "zzZZzzZZzzZZ");
	std::cout << "\e[0;34mkitten : (type: " << kitten->getType() << ")\e[0m" << std::endl;
	kitten->getIdea();
	std::cout << "\e[0;34mpuppy : (type: " << garfield.getType() << ")\e[0m" << std::endl;
	garfield.getIdea();
	std::cout << "\e[0;34mkits : (type: " << kits.getType() << ")\e[0m" << std::endl;
	kits.getIdea();
	kits = garfield;
	delete kitten;

	return (0);

}
