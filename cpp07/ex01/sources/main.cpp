/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:05:50 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/22 00:37:56 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	Data 		test;
	uintptr_t	serialized;
	Data		*deserialized;

	test.str_test = "new string";
	std::cout << " str: " << test.str_test << std::endl;
	test.nb_test = 42;
	std::cout << " int: " << test.nb_test << std::endl;
	test.float_test = 42.42f;
	std::cout << " float: " << test.float_test << "f" << std::endl;

	std::cout << std::endl;
	serialized = Serializer::serialize(&test);
	std::cout <<  "Serialized struct Data test is: ";
	std::cout << serialized << std::endl;
	std::cout <<  "Serialized struct Data test is: ";
	std::cout << std::hex << serialized << std::dec << " (in hexadecimal)" << std::endl;
	
	std::cout << std::endl;
	deserialized = Serializer::deserialize(serialized);
	std::cout <<  "Deserialized struct Data test is: " << std::endl;
	std::cout << "str: " << deserialized->str_test << std::endl;
	test.nb_test = 123;
	std::cout << "nb: " << deserialized->nb_test << std::endl;
	test.float_test = 123.321f;
	std::cout << "float: " << deserialized->float_test << std::endl;

}