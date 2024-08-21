/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EditFile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:59:32 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/21 17:06:05 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EditFile.hpp"
#include <stdio.h>

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

	if (stat(this->_file_name.c_str(), &type) == 0 && type.st_mode & S_IFDIR)
	{
		std::cerr << this->_file_name << ": is a directory" << std::endl;
		return (FAILURE);
	}
	this->_file_in.open(_file_name.c_str());
	if (!this->_file_in.good())
	{
		std::cerr << this->_file_name << ": unable to open file" << std::endl;
		this->_file_in.close();
		return (FAILURE);
	}
	else if (this->_file_in.is_open())
	{
		while (!this->_file_in.eof() && this->_file_in >> std::noskipws >> c)
			this->_content += c;
		std::cout << this->_file_in << " opened." << std::endl;
		std::cout << "Content : " << this->_content << std::endl;
	}
	this->_file_in.close();
	return (SUCCESS);
}

int	EditFile::writeOut(void)
{
	int			pos;
	struct stat	type;

	if (stat(this->_new_file_name.c_str(), &type) == 0 && type.st_mode & S_IFDIR)
	{
		std::cerr << this->_new_file_name << ": is a directory" << std::endl;
		return (FAILURE);
	}
	this->_file_out.open(_new_file_name.c_str());
	if (!this->_file_out.good())
	{
		std::cerr << this->_new_file_name << ": unable to open file" << std::endl;
		this->_file_out.close();
		return (FAILURE);
	}
	else if (this->_file_out.is_open())
	{
		std::cout << this->_new_file_name << " : created" << std::endl;
		std::cout << "Content : ";
		for (int i = 0; i < (int)this->_content.length(); i++)
		{
			pos = this->_content.find(this->_replace_from, i);
			if (pos == i && this->_replace_from.length() > 0)
			{
				std::cout << this->_replace_to;
				this->_file_out << this->_replace_to;
			}
			else
			{
				std::cout << this->_content[i];
				this->_file_out << this->_content[i];
			}
		}
		std::cout << std::endl;
	}
	this->_file_out.close();
	return (SUCCESS);
}