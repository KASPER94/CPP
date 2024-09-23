/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:41:21 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 21:52:00 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstring>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &cpy);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
		void	execute(Bureaucrat const & executor) const;
		std::string	getTarget(void) const;
};

// std::ostream	&operator<<(std::ostream &o, const RobotomyRequestForm &Form);

#endif