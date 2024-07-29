/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:15:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/07/29 19:01:42 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	reduce(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int	is_valid_number(std::string str)
{
	int	start;

	start = 0;
	if (str[0] == '-' || str[0] == '+')
		start = 1;
	for (unsigned long i = start; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
}

PhoneBook::PhoneBook(void)
{
	this->_nb_contacts = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(void)
{
	this->Contacts[this->_nb_contacts % 8].set_first_name();
	this->Contacts[this->_nb_contacts % 8].set_last_name();
	this->Contacts[this->_nb_contacts % 8].set_nickname();
	this->Contacts[this->_nb_contacts % 8].set_phone_number();
	this->Contacts[this->_nb_contacts % 8].set_darkest_secret();
	this->_nb_contacts++;
}