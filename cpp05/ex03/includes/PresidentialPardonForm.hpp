/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:41:17 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 21:50:18 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <cstring>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &cpy);

		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		void	execute(Bureaucrat const & executor) const;
		std::string	getTarget(void) const;
};

#endif