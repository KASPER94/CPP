/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:05:50 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/18 16:38:59 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.tpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>

int	main(void) {
	{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	}
	{
		MutantStack<int>	mutantStack1;

	std::cout << std::endl;
	std::cout << "Verifying MutantStack stack functions : " << std::endl;
	std::cout << "empty and size functions: the stack is empty." << std::endl;
	if (mutantStack1.empty()) {
		std::cout << "true";
		std::cout << " and the size is " << mutantStack1.size() << std::endl;
	}	
	else {
		std::cout << "false" << std::endl;
		std::cout << " and the size is " << mutantStack1.size() << std::endl;
	}
	std::cout << "push, pop and Top functions: " << std::endl;
	mutantStack1.push(42);
	if (mutantStack1.size() == 1)
		std::cout << "there is now : " << mutantStack1.top() << " and the size is " << mutantStack1.size() << std::endl;
	else
		std::cout << "push failed !" << std::endl;
	mutantStack1.push(84);
	if (mutantStack1.top() == 84 && mutantStack1.size() == 2)
		std::cout << "there is now : " << mutantStack1.top() << " and not 42. the size is " << mutantStack1.size() << std::endl;
	else if (mutantStack1.top() == 42)
		std::cout << "top failed !" << std::endl;
	mutantStack1.push(21);
	std::cout << "there is " << mutantStack1.size() << " with :" << std::endl;
	MutantStack<int>::iterator it3 = mutantStack1.begin();

	for (; it3 != mutantStack1.end(); it3++) {
		std::cout << *it3 << std::endl;
	}
	std::cout << " in the order they have been push" << std::endl;
	std::cout << " if we use pop() 21 should be gone : " << std::endl;
	mutantStack1.pop();
	it3 = mutantStack1.begin();
	for (; it3 != mutantStack1.end(); it3++) {
		std::cout << *it3 << std::endl;
	}
	mutantStack1.push(21);
	std::cout << " I push back 21 and want to delete not the first but the second elment" << std::endl;
	it3 = mutantStack1.begin() + 1;
	mutantStack1.erase(it3);
	it3 = mutantStack1.begin();
	for (; it3 != mutantStack1.end(); it3++) {
		std::cout << *it3 << std::endl;
	}
	}
	return 0;
}