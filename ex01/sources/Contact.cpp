/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:15:52 by skapersk          #+#    #+#             */
/*   Updated: 2024/07/29 19:08:55 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::set_last_name(void)
{
	std::cout << First name  > ;
	while (std::getline(std:cin, this->first_name))
	{
		if (!this->first_name.empty() && this->check_printable(this->first_name))
			break ;
		std::
	}
}