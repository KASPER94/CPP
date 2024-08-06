/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:38:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/06 17:58:09 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void	Harl::_debug(void)
{
	switch (this->_check_level)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			std::cout << "I love having extra bacon for my ";
			std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
			std:: cout << "I really do !" << std::endl << std::endl;
			break ;
		default:
			break ;

	}
}

void	Harl::_info(void)
{
	switch (this->_check_level)
	{
		case 0:
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			std::cout << "I cannot believe adding extra bacon costs more money. " << std::endl;
			std::cout << "You didn’t put enough bacon in my burger !" << std::endl;
			std:: cout << "If you did, I wouldn’t be asking for more !" << std::endl << std::endl;
			break ;
		default:
			break ;
	}
}

void	Harl::_warning(void)
{

	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. " << std:: endl;
	std:: cout << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::_error(void)
{
	switch (this->_check_level)
	{
		case 0:
		case 1:
		case 2:
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			std:: cout << "This is unacceptable ! I want to speak to the manager now." << std::endl << std::endl;
			break ;
		default:
			break ;
	}
}

void	Harl::complain(std::string level)
{
	void	(Harl::*func[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(str[i]) == 0)
				(this->*func[i])();
	}
}

int	Harl::set_check_level(std::string level)
{
	std::string	str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	this->_check_level = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level.compare(str[i]) == 0)
			this->_check_level = i;
	}
	if (this->_check_level == -1)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return (this->_check_level);
}
