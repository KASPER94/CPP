/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:21:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/05 11:14:14 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EditFile.hpp"

int	main(int ac, char **av)
{
	EditFile	*file;
	
	if (ac != 4)
	{
		std::cerr << "EditFile : wrong number of arguments" << std::endl;
		std::cerr << "./EditFile <filename> \"string to replace\" \"replacement string" << std::endl;
		return (FAILURE);
	}
	file = new EditFile(av{1}, av[2], av[3]);
	delete file;
	return (SUCCESS);
}