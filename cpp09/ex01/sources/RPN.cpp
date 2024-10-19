/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:07:09 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/19 18:01:12 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){

}

RPN::~RPN(){

}

RPN::RPN(const RPN &cpy) {
	*this = cpy;
}

RPN &RPN::operator=(const RPN &rhs) {
	this->_nbs= rhs._nbs;
	return (*this);
}


void	rtrim(std::string &s) {
	int	i = s.length() - 1;

	while (std::isspace(s[i]))
		i--;
    s = s.substr(0, i + 1);
}

void	ltrim(std::string &s) {
	int	i = 0;

	while (std::isspace(s[i]))
		i++;
    s = s.substr(i, s.length());
}

std::stack<std::string>	split_trim(std::string str, char c) {
	std::stack<std::string>	split;
	std::string					sub;

	int end = str.find(c);
	while (end != -1) {
		sub = str.substr(0, end);
		ltrim(sub);
		rtrim(sub);
		split.push(sub);
		str.erase(str.begin(), str.begin() + end + 1);
		end = str.find(c);
	}
	ltrim(str);
	rtrim(str);
	split.push(str);
	return (split);
}

bool RPN::checkData(const std::string Data) {
	std::stack<std::string> split;

	split = split_trim(Data, ' ');
	std::cout << split.top() << std::endl;
	return (true);
}

void	RPN::setData(const std::string Data) {
	try {
		checkData(Data);
	}
	catch (const RPN::InvalidData &e) {
		std::cerr << e.what() << std::endl;
	}
	this->_nbs.push(0);
}

const char *RPN::InvalidData::what() const throw() {
	return ((char *)"Data input do not respect the Reverse Polish Notation");
}
