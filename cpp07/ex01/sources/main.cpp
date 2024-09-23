/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:05:50 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/24 00:21:20 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void display0(int const & i) {
	std::cout << i << 0<< std::endl;
}

template<typename T>
void display0T(T const &t) {
	std::cout << t << 0 << std::endl;
}

int	main(void) {
	int tab[4] = {2, 3, 4, 1};
	iter(tab, 4, display0);
	iter(tab, 4, display0T);
	std::string ts[3] = {
	"Salut",
	"Ca",
	"Va ?"
	};
	iter(ts, 3, display0T);
}