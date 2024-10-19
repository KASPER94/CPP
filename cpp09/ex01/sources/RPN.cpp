/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:07:09 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/20 01:25:43 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
	this->_calc[0] = &RPN::add;
	this->_calc[1] = &RPN::sub;
	this->_calc[2] = &RPN::mult;
	this->_calc[3] = &RPN::div;
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

std::string	RPN::add(double a, double b) {
	return (dtoa(a + b));
}

std::string	RPN::sub(double a, double b){
	return (dtoa(a - b));
}

std::string	RPN::mult(double a, double b){
	return (dtoa(a * b));
}

std::string	RPN::div(double a, double b){
	if (b == 0)
		throw RPN::ImpossibleDividedByZero();
	return (dtoa(a / b));
}

static bool	isSign(std::string c) {
	if (c == "+" || c == "-" || c == "*" || c == "/")
		return (true);
	return (false);
}

static bool	checkNb(std::string c) {
	if (c.length() == 1)
		return (true);
	return (false);
}

bool RPN::checkData(const std::string Data) {
	std::stack<std::string> split;
	size_t	start;

	split = split_trim(Data, ' ');
	start = split.size();
	while (split.size()) {
		if (split.size() == start && !isSign(split.top().c_str())) {
			throw RPN::InvalidData();
		}
		else if ((split.size() == 1 || split.size() == 2) && !isdigit(split.top()[0])) {
			throw RPN::InvalidData();
		}
		else if (isdigit(split.top()[0])) {
			if (!checkNb(split.top())) {
				throw RPN::InvalidData();
			}
			this->_rpn.push(split.top());
			split.pop();
			std::cout << this->_rpn.top() << std::endl;
		}
		else if (isSign(split.top().c_str())) {
			this->_rpn.push(split.top());
			split.pop();
			std::cout << this->_rpn.top() << std::endl;
		}
		else 
			throw RPN::InvalidData();
	}
	return (true);
}

// void	RPN::calcul() {
// 	std::string	str;
// 	char		sign[] = {'+', '-', '*', '/'};
// 	double		a;
// 	double		b;

// }

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
