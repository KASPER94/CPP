/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:21:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/02 16:31:10 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z;

	std::cout << "============= heapZombies ==============" << std::endl;
	z = newZombie("Zombie");
	z->annouce();
	delete z;
	std::cout << std::endl;
	std::cout << "============= stackZombies =============" << std::endl;
	randomChump("RandomZombie");
	return (0);
}