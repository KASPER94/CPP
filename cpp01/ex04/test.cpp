/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:00:32 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/06 12:22:10 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/EditFile.hpp"
#include <stdio.h>
#include <iostream>

void	exec(std::string str)
{
	std::cout << "______________________________________________________________" << std::endl;
	std::cout <<					"cmd : " << str << std::endl;
	std::cout << "______________________________________________________________" << std::endl;
	system(str.c_str());
}

int	main(void)
{
	exec("./EditFile ./Makefile '#' A");
	// getchar();
	return (0);
}
