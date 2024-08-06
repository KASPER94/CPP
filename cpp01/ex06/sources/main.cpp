/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:21:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/06 18:00:18 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl		Harl;
	std::string	str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;

	if (ac != 2)
	{
		std::cerr << "HarlFilter: wrong number of arguments" << std::endl;
		std::cerr << "./HarlFilter \"Minimum severity level\"" << std::endl;
		return (1);
	}
	i = Harl.set_check_level(av[1]);
	switch (i)
	{
		case 0:
			Harl.complain(str[0]);
		case 1:
			Harl.complain(str[1]);
		case 2:
			Harl.complain(str[2]);
		case 3:
			Harl.complain(str[3]);
			break ;
		default:
			break ;
	}
	return (0);
}

