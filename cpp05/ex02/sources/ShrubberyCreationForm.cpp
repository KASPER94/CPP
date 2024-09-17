/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:41:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/17 16:05:06 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm: Constructor called with target (" << this->_target << ")" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm: Destructor with target (" << this->_target << ")" <<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy): AForm(cpy), _target(cpy._target) {
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs){
	(void)rhs;
	return (*this);
}

void	ShrubberyCreationForm::createFile() {
	this->_target.append("_shrubbery");
	this->_fileName = this->_target + "_shrubbery";
	this->_file_out.open(this->_fileName.c_str());
	if (this->_file_out.is_open()) {
		_file_out << "               ,@@@@@@@," << std::endl;
		_file_out << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		_file_out << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		_file_out << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
		_file_out << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		_file_out << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		_file_out << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		_file_out << "       |o|        | |         | |" << std::endl;
		_file_out << "       |.|        | |         | |" << std::endl;
		_file_out << "/_-/\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
		_file_out.close();
	}
}

void		ShrubberyCreationForm::beSigned(Bureaucrat &Bureaucrat) {
	(void)Bureaucrat;
}

