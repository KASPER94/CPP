/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:05:50 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 22:45:44 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int	main(void) {
	{
		std::cout << "Main from subject" << std::endl;
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";
		
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Aditional test" << std::endl;
		int			a = 10;
		int			b = 200;
		int			c = 10;
		int			*d = new int(100);
		int			*e = new int(2000);
		int			*f = new int(100);
		std::string	s1 = "abcdef";
		std::string	s2 = "uvwxyz";

		std::cout << "int  a: " << a << std::endl;
		std::cout << "int  b: " << b << std::endl;
		std::cout << "int  c: " << c << std::endl;
		std::cout << "int *d: " << *d << std::endl;
		std::cout << "addr &d: " << d << std::endl;
		std::cout << "int *e: " << *e << std::endl;
		std::cout << "addr &e: " << e << std::endl;
		std::cout << "int *f: " << *f << std::endl;
		std::cout << "addr &f: " << f << std::endl;
		std::cout << "str s1: " << s1 << std::endl;
		std::cout << "str s2: " << s2 << std::endl;

		std::cout << std::endl;
		std::cout << "swap(a, b) (int)" <<std::endl;
		::swap(a, b);
		std::cout << "int  a: " << a << std::endl;
		std::cout << "int  b: " << b <<  std::endl;

		std::cout << std::endl;
		std::cout << "swap(d, e) (intpointers)" << std::endl;
		::swap(d, e);
		std::cout << "int  *d: " << *d <<  std::endl;
		std::cout << "addr &d: " << d <<  std::endl;
		std::cout << "int  *e: " << *e <<  std::endl;
		std::cout << "addr &e: " << e <<  std::endl;

		std::cout << std::endl;
		std::cout << "swap(s1, s2) (str)" <<std::endl;
		::swap(s1, s2);
		std::cout << "str s1: " << s1 << std::endl;
		std::cout << "str s2: " << s2 << std::endl;

		std::cout << std::endl;
		std::cout << "max(" << a << ", " << b << ") = " << ::max(a, b) << std::endl;

		std::cout << "max(" << *d << ", " << *e << ")" "(int pointers) = " << ::max(*d, *e) << std::endl;

		std::cout << "max(" << d << ", " << e << ")" "(int address) = " << ::max(d, e) << std::endl;
		
		std::cout << "max(" << s1 << ", " << s2 << ") = " << ::max(s1, s2) << std::endl;

		std::cout << std::endl;
		std::cout << "min(" << a << ", " << b << ") = " << ::min(a, b) << std::endl;

		std::cout << "min(" << *d << ", " << *e << ")" "(int pointers) = " << ::min(*d, *e) << std::endl;

		std::cout << "min(" << d << ", " << e << ")" "(int address) = " << ::min(d, e) << std::endl;
		
		std::cout << "min(" << s1 << ", " << s2 << ") = " << ::min(s1, s2) << std::endl;
	}
	return 0;
}