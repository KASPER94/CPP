/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:15:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/07/31 10:17:54 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

std::string	limit(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

std::string int_to_string(int num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

void print_centered(std::string str, int width)
{
	int padding;
    int len;

	len = str.length();
    if (len >= width)
        std::cout << str.substr(0, width);
    else 
	{
        padding = (width - len) / 2;
        for (int i = 0; i < padding; i++) 
			std::cout << ' ';
        std::cout << str;
        for (int i = 0; i < (width - len - padding); i++) 
			std::cout << ' ';
    }
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
	return (1);
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
	this->_contacts[this->_nb_contacts % 8].set_first_name();
	this->_contacts[this->_nb_contacts % 8].set_last_name();
	this->_contacts[this->_nb_contacts % 8].set_nickname();
	this->_contacts[this->_nb_contacts % 8].set_phone_number();
	this->_contacts[this->_nb_contacts % 8].set_darkest_secret();
	this->_nb_contacts++;
}

void	PhoneBook::print(void)
{
	unsigned long	nb_entries;

 	std::cout << "┌──────────┬───────────┬──────────┬──────────┐" << std::endl;
    std::cout << "│  index   │ firstname │ lastname │ nickname │" << std::endl;
    std::cout << "├──────────┼───────────┼──────────┼──────────┤" << std::endl;
    if (this->_nb_contacts > 7)
        nb_entries = 8;
    else
        nb_entries = this->_nb_contacts;
    for (unsigned int i = 0; i < nb_entries; i++) {
        std::cout << "│";
		print_centered(int_to_string(i), 10);
        std::cout << "│";
		print_centered(limit(this->_contacts[i].get_first_name()), 11);
        std::cout << "│";
		print_centered(limit(this->_contacts[i].get_last_name()), 10);
        std::cout << "│";
		print_centered(limit(this->_contacts[i].get_nickname()), 10);
        std::cout << "│" << std::endl;
    }
    std::cout << "└─────────┴────────────┴────────────┴──────────┘" << std::endl;
}

void	PhoneBook::search(void)
{
	
}
