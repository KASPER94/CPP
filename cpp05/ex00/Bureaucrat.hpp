/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:21:04 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/23 11:08:37 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <cstring>

class Bureaucrat {
	private:
		const std::string _name;
		int	_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &cpy);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &rhs);
		std::string getName() const;
		int getGrade() const;
		void	GradeTooHighException() const;
		void	GradeTooLowException() const;
		void	incrementGrade();
		void	decrementGrade();
}

#endif
