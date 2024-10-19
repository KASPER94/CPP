/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:59 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/20 00:27:11 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av) {
	RPN	lst;

	if (ac != 2) {
		std::cerr << "./RPN needs an argement and only one like : ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
	}
	try {
		lst.setData(av[1]);
		// lst.calcul();
	}
	catch (RPN::InvalidData &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
