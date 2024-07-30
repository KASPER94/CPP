/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:15:52 by skapersk          #+#    #+#             */
/*   Updated: 2024/07/30 11:40:56 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::set_first_name(void)
{
	std::cout << "First name  > ";
	while (std::getline(std::cin, this->_first_name))
	{
		if (!this->_first_name.empty())
			break ;
		std::cerr << "This field can't be empty, and must contains only printable char" << std::endl;
		std::cout << "Fist name > ";
	}
}

void	Contact::set_last_name(void)
{
	std::cout << "Last name  > ";
	while (std::getline(std::cin, this->_first_name))
	{
		if (!this->_first_name.empty())
			break ;
		std::cerr << "This field can't be empty, and must contains only printable char" << std::endl;
		std::cout << "Last name > ";
	}
}

void	Contact::set_nickname(void)
{
	std::cout << "Nickname  > ";
	while (std::getline(std::cin, this->_first_name))
	{
		if (!this->_first_name.empty())
			break ;
		std::cerr << "This field can't be empty, and must contains only printable char" << std::endl;
		std::cout << "Nickname > ";
	}
}

void	Contact::set_phone_number(void)
{
	std::cout << "Phone number  > ";
	while (std::getline(std::cin, this->_first_name))
	{
		if (!this->_first_name.empty())
			break ;
		std::cerr << "This field can't be empty, and must contains only printable char" << std::endl;
		std::cout << "Phone number > ";
	}
}

void	Contact::set_darkest_secret(void)
{
	std::cout << "Darkest secret  > ";
	while (std::getline(std::cin, this->_first_name))
	{
		if (!this->_first_name.empty())
			break ;
		std::cerr << "This field can't be empty, and must contains only printable char" << std::endl;
		std::cout << "Darkest secret > ";
	}
}

std::string	Contact::get_first_name(void)
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void)
{
	return (this->_last_name);
}

std::string	Contact::get_nickname(void)
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number(void)
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (this->_darkest_secret);
}