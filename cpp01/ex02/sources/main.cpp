/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:15:28 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/04 14:39:17 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str="HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "============= ADRESS ==============" << std::endl;
	std::cout << "Adress of str (&str) : " << &str << std::endl;
	std::cout << "Adress of stringPTR : " << stringPTR << std::endl;
	std::cout << "Adress of string REF : " << &stringREF << std::endl;

	std::cout << "============= VALUE ==============" << std::endl;
	std::cout << "Value of str : " << str << std::endl;
	std::cout << "Value of stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value of stringREF : " << stringREF << std::endl;
}