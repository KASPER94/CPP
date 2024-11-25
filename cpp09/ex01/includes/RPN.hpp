/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:36 by skapersk          #+#    #+#             */
/*   Updated: 2024/11/25 18:35:34 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stack>
#include <iomanip>
#include <sstream>


class RPN {
	private:
		typedef double (RPN::*func)(double, double);
		std::stack<std::string>	_nbs;
		std::stack<std::string>	_rpn;
		func	_calc[4];
		
		// void	reverseStack();
		double	add(double a, double b);
		double	sub(double a, double b);
		double	mult(double a, double b);
		double	div(double a, double b);

	public:
		RPN();
		~RPN();
		RPN(const RPN &cpy);

		RPN &operator=(const RPN &rhs);
		bool checkData(const std::string data);
		void	calcul();
		class InvalidData : std::exception {
			public :
				const char *what() const throw();
		};
		class ImpossibleDividedByZero : std::exception {
			public :
				const char *what() const throw();
		};
};
