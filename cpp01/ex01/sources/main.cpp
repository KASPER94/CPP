/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:21:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/02 18:28:21 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char **av)
{
	Zombie		*horde;
	int			nbZ;
	std::string	name = "Zombie";

	if (ac == 1 || ac > 2)
		nbZ = 12;
	else if (std::atoi(av[1]) <= 0)
	{
		std::cerr << "Negative numbers or 0 are prohibited" << std::endl;
		return (1);
	}
	else
		nbZ = std::atoi(av[1]);
	horde = zombieHorde(nbZ, name);
	for (int i = 0; i < nbZ; i++)
		horde[i].annouce();
	delete [] horde;
	return (0);
}