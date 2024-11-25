/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:07:09 by skapersk          #+#    #+#             */
/*   Updated: 2024/11/25 18:36:38 by skapersk         ###   ########.fr       */
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
	this->_rpn= rhs._rpn;
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
	if (str == "")
		return (split);
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

double	RPN::add(double a, double b) {
	return (a + b);
}

double	RPN::sub(double a, double b){
	return (a - b);
}

double	RPN::mult(double a, double b){
	return (a * b);
}

double	RPN::div(double a, double b){
	if (b == 0)
		throw RPN::ImpossibleDividedByZero();
	return (a / b);
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
		}
		else if (isSign(split.top().c_str())) {
			this->_rpn.push(split.top());
			split.pop();
		}
		else 
			throw RPN::InvalidData();
	}
	return (true);
}

void RPN::calcul() {
	char sign[] = {'+', '-', '*', '/'};
	std::stack<double> operandStack;

	while (!this->_rpn.empty()) {
		std::string token = this->_rpn.top();
		this->_rpn.pop();

		if (isSign(token)) {
			if (operandStack.size() < 2) {
				throw RPN::InvalidData();
			}
			double b = operandStack.top();
			operandStack.pop();
			double a = operandStack.top();
			operandStack.pop();

			for (int i = 0; i < 4; i++) {
				if (token == std::string(1, sign[i]))
					operandStack.push((this->*_calc[i])(a, b));
			}
		} else {
			operandStack.push(std::atof(token.c_str()));
		}
	}
	if (operandStack.size() != 1) {
		throw RPN::InvalidData();
	}
	std::cout << operandStack.top() << std::endl;
}

const char *RPN::InvalidData::what() const throw() {
	return ((char *)"Error: Data input do not respect the Reverse Polish Notation");
}

const char *RPN::ImpossibleDividedByZero::what() const throw() {
	return ((char *)"Error: Division by zero is not allowed!");
}
