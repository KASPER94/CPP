/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:05:50 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/10 00:54:26 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <array>
#include <vector>

int	main(void) {
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	srand(time(NULL) * getpid() * getpid());

	std::vector<int> vect(10);
	std::generate(vect.begin(), vect.end(), rand);
	Span sp2 = Span(10);
	sp2.addNumber<std::vector>(vect);
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	std::cout << std::endl;
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++) {
		if (*it == *std::max_element(vect.begin(), vect.end())
			|| *it == *std::min_element(vect.begin(), vect.end()))
			std::cout << "\033[32m" << *it << "\033[0m" << std::endl;
		if (*it == sp2._tmpIt
			|| *it == sp2._tmpIt2)
			std::cout << "\033[31m" << *it << "\033[0m" << std::endl;
		std::cout << *it << std::endl;
	}
	return 0;
}