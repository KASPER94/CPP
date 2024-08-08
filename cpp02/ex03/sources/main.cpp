/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:21:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/08 19:35:19 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	const Fixed	a(Fixed(5.05f) * Fixed(2));
	const Fixed	b(Fixed(3.12f) * Fixed(-12));

	Point	p01;
	Point	p02(5.2f, 1.3f);
	Point	p03(a.toFloat(), b.toFloat());
	// Point	p04 = p03;
	Point	p04(5.6f, -14.6f);

	std::cout << "p01: " << p01 << std::endl;
	std::cout << "p02: " << p02 << std::endl;
	std::cout << "p03: " << p03 << std::endl;
	std::cout << "p04: " << p04 << std::endl;

	Point	p11(5.0f, 2.0f);
	Point	p12(-4.2f, -3.3f);
	Point	p13(0.5f, 5.3f);
	Point	p14(1.1f, 1.1f);

	if (bsp(p01, p02, p03, p04))
		std::cout << "\e[0;32mp04 is in triangle p01, p02, p03\e[0m" << std::endl;
	else
		std::cout << "\e[0;31mp04 is not in triangle p01, p02, p03\e[0m" << std::endl;

	std::cout << "p11: " << p11 << std::endl;
	std::cout << "p12: " << p12 << std::endl;
	std::cout << "p13: " << p13 << std::endl;
	std::cout << "p14: " << p14 << std::endl;

	if (bsp(p11, p12, p13, p14))
		std::cout << "\e[0;32mp14 is in triangle p11, p12, p13\e[0m" << std::endl;
	else
		std::cout << "\e[0;31mp14 is not in triangle p11, p12, p13\e[0m" << std::endl;

	return 0;
}

