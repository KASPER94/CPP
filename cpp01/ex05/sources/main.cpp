/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:21:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/06 17:02:45 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl Harl;

	std::cout << "DEBUG : " << std::endl;
	Harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "INFO : " << std::endl;
	Harl.complain("INFO");
	std::cout << std::endl;
	std::cout << "WARNING : " << std::endl;
	Harl.complain("WARNING");
	std::cout << std::endl;
	std::cout << "ERROR : " << std::endl;
	Harl.complain("ERROR");
	std::cout << std::endl;
	std::cout << "WRONG ARG : " << std::endl;
	Harl.complain("WRONGGGGGG ARG");
	std::cout << std::endl;
	return (0);
}

