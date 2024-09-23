/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:55:22 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/23 16:17:06 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <cstring>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool		_signature;
		const int	_gradeToSign;
		const int	_gradeToExe;

	public:
		AForm();
		AForm(std::string name, bool sign, const int gradeToSign, const int gradeToExe);
		virtual ~AForm();
		AForm(const AForm &cpy);
		AForm &operator=(const AForm &rhs);

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
		class NotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		std::string	getName(void) const;
		bool		getSignature(void) const;
		int			getGradeToExe(void) const;
		int 		getGradeToSign(void) const;
		virtual void		execute(Bureaucrat const & executor) const = 0;
		virtual void		beSigned(Bureaucrat &Bureaucrat);
};

std::ostream	&operator<<(std::ostream &o, const AForm &AForm);

#endif
