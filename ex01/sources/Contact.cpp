/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:15:52 by skapersk          #+#    #+#             */
/*   Updated: 2024/07/31 11:34:09 by skapersk         ###   ########.fr       */
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

void	Contact::print_contact(void)
{
	std::cout << "First name : " << this->_first_name << std::endl;
	std::cout << "Last name : " << this->_last_name << std::endl;
	std::cout << "Nickname : " << this->_nickname << std::endl;
	std::cout << "Phone number : " << this->_phone_number << std::endl;
	std::cout << "Darkest secret : " << this->_darkest_secret << std::endl;
}

int		Contact::check_printable(std::string str)
{
	for (unsigned int i; i < str.length(); i++)
	{
		if (!std::isprint(str[i]))
			return (0);
	}
	return (1);
}

void	Contact::set_first_name(void)
{
	std::cout << "First name  > ";
	while (std::getline(std::cin, this->_first_name))
	{
		if (!this->_first_name.empty() && this->check_printable(this->_first_name))
			break ;
		std::cerr << "This field can't be empty, and must contains only printable char" << std::endl;
		std::cout << "Fist name > ";
	}
}

void	Contact::set_last_name(void)
{
	std::cout << "Last name  > ";
	while (std::getline(std::cin, this->_last_name))
	{
		if (!this->_last_name.empty() && check_printable(this->_last_name))
			break ;
		std::cerr << "This field can't be empty, and must contains only printable char" << std::endl;
		std::cout << "Last name > ";
	}
}

void	Contact::set_nickname(void)
{
	std::cout << "Nickname  > ";
	while (std::getline(std::cin, this->_nickname))
	{
		if (!this->_nickname.empty() && check_printable(this->_nickname))
			break ;
		std::cerr << "This field can't be empty, and must contains only printable char" << std::endl;
		std::cout << "Nickname > ";
	}
}

void	Contact::set_phone_number(void)
{
	std::cout << "Phone number  > ";
	while (std::getline(std::cin, this->_phone_number))
	{
		if (!this->_phone_number.empty() && check_printable(this->_phone_number))
			break ;
		std::cerr << "This field can't be empty, and must contains only printable char" << std::endl;
		std::cout << "Phone number > ";
	}
}

void	Contact::set_darkest_secret(void)
{
	std::cout << "Darkest secret  > ";
	while (std::getline(std::cin, this->_darkest_secret))
	{
		if (!this->_darkest_secret.empty() && check_printable(this->_darkest_secret))
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