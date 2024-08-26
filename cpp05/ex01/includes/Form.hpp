/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:55:22 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/26 15:40:17 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM-hpp

# include <iostream>
# include <cstring>

class Form {
	private:
		const std::string _name;
		bool	_signature;
		const int	_grade;
		const int	_requiredGrade;

	public:
		Form(std::string _name, );
		~Form();
		Form(const Form &cpy);
		Form &operator=(const Form &rhs);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		}
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		}
		int getGrade() const;
		bool	beSigned(Bureaucrat &Bureaucrat);
		void	signForm();
};

#endif
