/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:05:50 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/10 18:00:21 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>
#include <Array.tpp>
#include <cstdlib>

#define MAX_VAL 750

void	rand_int(Array<int> &array) {
	for (unsigned int i = 0; i < array.size(); i++)
		array[i] = rand() % 10;
}

void	print_int(Array<int> &array) {
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void	print_str(Array<std::string> &array) {
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << i << ": " << array[i] << std::endl;
	std::cout << std::endl;
}

int	main(void) {
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;

	std::cout << std::endl;
	std::cout << "Creating an Array<int> of size 25 & Assigning random values to Array<int> and printing it" <<std::endl;
	Array<int>	int_array(25);
	rand_int(int_array);
	print_int(int_array);

	std::cout << std::endl;
	std::cout << "Copying an Array<int> with Array<int>(cpy) and operator = and printing all 3 arrays" << std::endl;
	Array<int>	int_copy(int_array);
	Array<int>	*int_operator = new Array<int>(10);
	*int_operator = int_copy;
	print_int(int_array);
	print_int(int_copy);
	print_int(*int_operator);

	delete int_operator;

	std::cout << std::endl;
	std::cout << "Creating an Array<std::string> of size 10, and printing it" << std::endl;
	Array<std::string>	str_array(10);
	print_str(str_array);

	std::cout << std::endl;
	std::cout << "Assigning values to Array<std::string> and printing it" << std::endl;
	str_array[0] = "a string";
	str_array[3] = "an other string";
	str_array[8] = "and an other one";
	print_str(str_array);

	std::cout << std::endl;
	std::cout << "Copying an Array<std::string> with Array<std::string>(cpy) and operator = and printing all 3 arrays" << std::endl;
	Array<std::string>	str_copy(str_array);
	Array<std::string>	*str_operator = new Array<std::string>(10);
	*str_operator = str_copy;
	print_str(str_array);
	print_str(str_copy);
	print_str(*str_operator);

	std::cout << std::endl;
	std::cout << "Trying to assigning values (0 to 11: 2 out of bounds) to the first array and printing all 3 arrays" <<std::endl;
	for (unsigned int i = 0; i < 12; i++)
	{
		try {
			str_array[i] = "qwertyuiop";
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	print_str(str_array);
	print_str(str_copy);
	print_str(*str_operator);

	delete str_operator;
	return 0;
}
