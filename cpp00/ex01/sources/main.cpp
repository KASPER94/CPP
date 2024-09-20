/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:05:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/04 15:53:33 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	// char		line[512];
	std::string	input;

	std::cout << "> ";
	while (std::cin >> input)
	{
		if (!input.compare("EXIT"))
			break ;
		if (!input.compare("ADD"))
			phone_book.add();
		else if (!input.compare("SEARCH"))
			phone_book.search();
		std::cout << "> ";
	}
	std::cout << std::endl;
	return (0);
}
