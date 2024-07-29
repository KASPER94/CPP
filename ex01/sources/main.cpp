/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:05:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/07/29 17:04:34 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	char		line[512];

	std::cout << "> ";
	while (std::cin.getline(line, 512) && strcmp(line, "EXIT") != 0)
	{
		phone_book.Contact = line;
	}
	std::cout << phone_book.Contact;
	std::cout << std::endl;
	return (0);
}