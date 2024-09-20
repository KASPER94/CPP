/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:41:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/19 23:37:47 by skapersk         ###   ########.fr       */
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

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::ofstream	file_out;
	std::string		fileName;
	
	if (this->getSignature())
		throw AForm::FormAlreadySigned();
    else if (executor.getGrade() <= this->getGradeToExe()) {
        fileName = this->_target + "_shrubbery";
        file_out.open(fileName.c_str());
        if (file_out.is_open()) {
            file_out << "               ,@@@@@@@," << std::endl;
            file_out << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
            file_out << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
            file_out << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
            file_out << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
            file_out << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
            file_out << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
            file_out << "       |o|        | |         | |" << std::endl;
            file_out << "       |.|        | |         | |" << std::endl;
            file_out << "/_-/\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
            file_out.close();
        }
    }
    else
        throw Bureaucrat::GradeTooLowException();
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}
