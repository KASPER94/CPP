/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:55:22 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/26 17:00:41 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <cstring>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool	_signature;
		const int	_grade;
		const int	_requiredGrade;

	public:
		Form(std::string name, bool sign, const int grade, const int reqGrade);
		~Form();
		Form(const Form &cpy);
		Form &operator=(const Form &rhs);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		int getGrade() const;
		bool	beSigned(Bureaucrat &Bureaucrat);
};

#endif
