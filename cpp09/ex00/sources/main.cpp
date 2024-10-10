/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:05:50 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/10 13:57:31 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

bool checkValidDb(const std::string db) {
	std::ifstream myfile;

	myfile.open(db);
	if (myfile.good()) {
		(void)myfile;
	}
	
}

int	main(int ac, char **av) {
	BitcoinExchange btc;

	if (ac != 2) {
		std::cerr <<  "Error: Argument needed ./btc path/to/<data_base>" << std::endl;
		return (1);
	}
	if (!checkValidDb(av[1])) {
		std::cerr <<  "Error: Argument needed ./btc path/to/<data_base>" << std::endl;
		return (1);
	}
	return (0);
}