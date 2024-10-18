/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:05:50 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/18 15:36:12 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.tpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

void	print(int &i) {
	std::cout << i << std::endl;
}

template<class T, class Func>
void forEach(T first, T last, Func f) {
	for (; first != last; ++first) {
		f(*first);
	}
}

int	main(void) {
	int	ints[] = {4, 7, 3, 8, 7, 1, 6, 3, 5, 8, 9};
	int	*finded_int;

	std::cout << "Initializing containers with integers 4, 7, 3, 8, 7, 1, 6, 3, 5, 8, 9" << std::endl;
	std::vector<int> vec(ints, ints + sizeof(ints) / sizeof(int));
	std::deque<int> deq(ints, ints + sizeof(ints) / sizeof(int));
	std::list<int> lis(ints, ints + sizeof(ints) / sizeof(int));
	forEach(vec.begin(), vec.end(), print);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Searching 7 in vector container..." << std::endl;
	try {
		finded_int = ::easyfind(vec, 7);
		std::cout << "Adding 10 to the found integer and printing the container ints" << std::endl;
		*finded_int += 10;
		forEach(vec.begin(), vec.end(), print);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Container does not contains this integer" << std::endl;
	}
	std::cout << "Searching 2 in deque container..." << std::endl;
	try {
		finded_int = ::easyfind(deq, 2);
		std::cout << "Adding 10 to the found integer and printing the container ints" << std::endl;
		*finded_int += 10;
		forEach(deq.begin(), deq.end(), print);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Container does not contains this integer" << std::endl;
	}
	std::cout << "Searching 9 in list container..." << std::endl;
	try {
		finded_int = ::easyfind(lis, 9);
		std::cout <<"Adding 10 to the found integer and printing the container ints" << std::endl;
		*finded_int += 10;
		forEach(lis.begin(), lis.end(), print);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Container does not contains this integer" << std::endl;
	}
	return (0);
}
