/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EditFile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:59:32 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/05 11:23:08 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EditFile.hpp"

EditFile::EditFile(std::string name, std::string s1, std::string s2): _file_name(name), _replace_from(s1), _replace_to(s2)
{
	this->_new_file_name = this->_file_name;
	this->_new_file_name.append(".replace");
	std::cout << "EditFile object created \n File to open: " << this->_file_name << std::endl;
	std::cout << "String to replace: " << this->_replace_from << std::endl;
	std::cout << "Replacement string: " << this->_replace_to << std::endl;
}

EditFile::~EditFile()
{
	std::cout << "EditFile object deleted \n File to open: " << this->_file_name << std::endl;
	std::cout << "String to replace: " << this->_replace_from << std::endl;
	std::cout << "Replacement string: " << this->_replace_to << std::endl;
}

int	EditFile::readIn(void)
{
	char		c;
	struct stat	type;

}