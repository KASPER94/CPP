/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:05:50 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/11 14:46:14 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

void display0(int const & i) {
	std::cout << i << 0 << std::endl;
}

int	set_int(void) {
	int i = std::rand();
	return (i);
}

template<typename T>
void display0T(T const &t) {
	std::cout << t << "0T" << std::endl;
}

int	main(void) {
	int tab[10];

	std::srand(time(NULL) * getpid() * getpid());
	for (int i = 0; i < 10; i++) {
		tab[i] = set_int();
	}
	iter(tab, 10, display0);
	std::cout << std::endl;
	iter(tab, 10, display0T);
	std::cout << std::endl;
	std::string ts[3] = {
	"Salut",
	"Ca",
	"Va ?"
	};
	iter(ts, 3, display0T);
}
