/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:06:36 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/19 17:50:51 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stack>

class RPN {
	private:
		std::stack<std::string>	_nbs;
	public:
		RPN();
		~RPN();
		RPN(const RPN &cpy);

		RPN &operator=(const RPN &rhs);
		bool parsingLine(const std::string data);
		bool checkData(const std::string data);
		void	setData(const std::string Data);
		class InvalidData : std::exception {
			public :
				const char *what() const throw();
		};
};
