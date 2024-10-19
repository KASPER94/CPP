/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:07:09 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/19 23:28:35 by peanut           ###   ########.fr       */
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

std::string dtoa(double nb) {
	std::ostringstream s;
	std::string		str;

	s << std::setprecision(8) << std::fixed << nb;
	str = s.str();
	str = str.erase(str.find_last_not_of('0') + 1);
	if (str[str.length() - 1] == '.')
		str += "0";
	return (str);
}

std::string	add(double a, double b) {
	return (dtoa(a + b));
}

std::string	sub(double a, double b){
	return (dtoa(a - b));
}

std::string	mult(double a, double b){
	return (dtoa(a * b));
}

std::string	div(double a, double b){
	if (b == 0)
		throw RPN::ImpossibleDividedByZero();
	return (dtoa(a / b));
}

bool RPN::checkData(const std::string Data) {
	std::stack<std::string> split;

	split = split_trim(Data, ' ');
	
	return (true);
}

void	RPN::setData(const std::string Data) {
	try {
		checkData(Data);
	}
	catch (const RPN::InvalidData &e) {
		std::cerr << e.what() << std::endl;
	}
	// this->_nbs.push(0);
}

const char *RPN::InvalidData::what() const throw() {
	return ((char *)"Data input do not respect the Reverse Polish Notation");
}

const char *RPN::ImpossibleDividedByZero::what() const throw() {
	return ((char *)"Data input do not respect the Reverse Polish Notation");
}
