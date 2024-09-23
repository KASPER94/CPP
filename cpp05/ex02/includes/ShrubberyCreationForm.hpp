/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:41:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 21:52:04 by skapersk         ###   ########.fr       */
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

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		void	execute(Bureaucrat const & executor) const;
		std::string	getTarget(void) const;
};

// std::ostream	&operator<<(std::ostream &o, const ShrubberyCreationForm &Form);

#endif