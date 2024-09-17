/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:41:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/17 18:05:44 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <cstring>
# include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;
		std::string	_fileName;
		std::ofstream	_file_out;

	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		void	createFile();
		void	execute(Bureaucrat &Executor);
};

#endif