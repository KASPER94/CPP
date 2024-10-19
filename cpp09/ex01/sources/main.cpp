/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:59 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/19 17:24:46 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av) {
	RPN	lst;

	if (ac != 2) {
		std::cerr << "./RPN needs an argement and only one like : ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
	}
	lst.setData(av[1]);
	return (0);
}
