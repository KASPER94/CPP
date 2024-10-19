/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:36 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/20 01:27:59 by peanut           ###   ########.fr       */
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
		typedef std::string (RPN::*func)(double, double);
		std::stack<std::string>	_nbs;
		std::stack<std::string>	_rpn;
		func	_calc[4];
		
		// void	reverseStack();
		std::string	add(double a, double b);
		std::string	sub(double a, double b);
		std::string	mult(double a, double b);
		std::string	div(double a, double b);

	public:
		RPN();
		~RPN();
		RPN(const RPN &cpy);

		RPN &operator=(const RPN &rhs);
		bool parsingLine(const std::string data);
		bool checkData(const std::string data);
		void	setData(const std::string Data);
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
