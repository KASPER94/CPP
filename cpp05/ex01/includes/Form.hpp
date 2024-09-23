/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:55:22 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 14:50:11 by skapersk         ###   ########.fr       */
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
		bool		_signature;
		const int	_gradeToSign;
		const int	_gradeToExe;

	public:
		Form();
		Form(std::string name, const int gradeToSign, const int gradeToExe);
		~Form();
		Form(const Form &cpy);
		Form &operator=(const Form &rhs);

		class FormGradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormGradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormAlreadySigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		std::string	getName(void) const;
		bool		getSignature(void) const;
		int			getGradeToExe(void) const;
		int 		getGradeToSign(void) const;
		void		beSigned(Bureaucrat &Bureaucrat);
};

std::ostream	&operator<<(std::ostream &o, const Form &Form);

#endif
