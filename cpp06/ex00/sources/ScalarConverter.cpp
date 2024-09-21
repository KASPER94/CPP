/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:00:31 by skapersk          #+#    #+#             */
/*   Updated: 2024/09/22 00:10:39 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {

}

ScalarConverter::~ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy) {
	(void)cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	(void)rhs;
	return(*this);
}

static bool	isInt(std::string str) {
	size_t i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; i < str.length(); i++) {
		if (isdigit(str[i]))
			continue ;
		else
			return (false);
	}
	return (true);
}

static bool isFloat(std::string str) {
	size_t i = 0;
	bool hasPoint = false;

	if (str[str.length() - 1] != 'f')
		return (false);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '.')
		return (false);
	if (str == "+inff" || str == "-inff" || str == "nanf")
		return (true);
	for (; i < str.length() - 1; i++) {
		if (isdigit(str[i])) {
			continue ;
		}
		else if (str[i] == '.' && !hasPoint) {
			hasPoint = true;
			continue;
		}
		else
			return (false);
	}
	return (true);
}

static bool isDouble(std::string str) {
	size_t i = 0;
	bool hasPoint = false;

	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '.')
		return (false);
	if (str == "+inf" || str == "-inf" || str == "nan")
		return (true);
	for (; i < str.length(); i++) {
		if (isdigit(str[i])) {
			continue ;
		}
		else if (str[i] == '.' && !hasPoint) {
			hasPoint = true;
			continue;
		}
		else
			return (false);
	}
	return (true);
}

static e_type getType(std::string str) {
	if (str.length() == 0)
		return (CHAR);
	if (str.length() == 1) {
		if (isdigit(str[0]))
			return (INT);
		else if (isascii(str[0])) {
			return (CHAR);
		}
	}
	else if (str.length() > 0) {
		if (isInt(str))
			return (INT);
		if (isFloat(str))
			return (FLOAT);
		if (isDouble(str))
			return (DOUBLE);
	}
	return (NONE);
}

std::string printPointNb(double nb) {
	std::ostringstream	strout;
	std::string			str;

	strout << std::fixed << nb;
	str = strout.str();
	str = str.erase(str.find_last_not_of('0') + 1);
	if (str[str.length() - 1] == '.')
		str += "0";
	return (str);
}

static void convertChar(char s) {
	if (!isprint(s))
		std::cout << " char: Non printable" << std::endl;
	else
			std::cout << " char: " << s << std::endl;
		std::cout << " int: " << static_cast<int>(s) << std::endl;
		std::cout << " float: " << printPointNb(static_cast<float>(s)) << std::endl;
		std::cout << " double: " << printPointNb(static_cast<double>(s)) << std::endl;
}

static bool	checkIntOverflow(std::string str) {
	if (str[0] == '-') {
		if (str.length() > 11)
			return (true);
		else if (str.length() == 11 && str.compare("-2147483648") > 0)
			return (true);
	}
	else if (str[0] == '+') {
		if (str.length() > 11)
			return (true);
		else if (str.length() == 11 && str.compare("+2147483647") > 0)
			return (true);
	}
	else {
		if (str.length() > 10) 
			return (true);
		else if (str.length() == 10 && str.compare("2147483647") > 0)
			return (true);
	}
	return (false);
}

static void convertInt(std::string str) {
	bool	intOverflow = checkIntOverflow(str);
	int		nb;

	if (!intOverflow)
		nb = std::atoi(str.c_str());
	if (!intOverflow) {
		if (isascii(nb)) {
			if (isprint(nb))
				std::cout << " char: " << static_cast<char>(nb) << std::endl;
			else
				std::cout << " char: Non printable" << std::endl;
		}
		else 
			std::cout << " char: Impossible convertion" << std::endl;
		std::cout << " int: " << nb << std::endl;
		std::cout << " float: " << printPointNb(static_cast<float>(nb)) << "f" << std::endl;
		std::cout << " double: " << printPointNb(static_cast<double>(nb)) << std::endl;
	}
	else {
		std::cout << " char: Impossible convertion" << std::endl;
		std::cout << " int: Impossible convertion" << std::endl;
		std::cout << " float: Impossible convertion" << std::endl;
		std::cout << " double: Impossible convertion" << std::endl;
	}
}

static void convertFloat(std::string str) {
	bool	intOverflow = false;
	float		nb;

	nb = std::strtof(str.c_str(), NULL);
	if (static_cast<float>(nb) < static_cast<float>(INT_MIN) || nb > static_cast<float>(INT_MAX)
		|| str == "+inff" || str == "-inff" || str == "nanf" )
		intOverflow = true;
	if (!intOverflow) {
		if (isascii(nb)) {
			if (isprint(nb))
				std::cout << " char: " << static_cast<char>(nb) << std::endl;
			else
				std::cout << " char: Non printable" << std::endl;
		}
		else 
			std::cout << " char: Impossible convertion" << std::endl;
		std::cout << " int: " << static_cast<int>(nb) << std::endl;
		std::cout << " float: " << printPointNb(nb) << "f" << std::endl;
		std::cout << " double: " << printPointNb(static_cast<double>(nb)) << std::endl;
	}
	else {
		std::cout << " char: Impossible convertion" << std::endl;
		std::cout << " int: Impossible convertion" << std::endl;
		std::cout << " float: " << printPointNb(nb) << "f" << std::endl;
		std::cout << " double: " << printPointNb(static_cast<double>(nb)) << std::endl;
	}
}

static void convertDouble(std::string str) {
	bool	intOverflow = false;
	float		nb;

	nb = std::strtod(str.c_str(), NULL);
	if (static_cast<double>(nb) < static_cast<double>(INT_MIN) || nb > static_cast<double>(INT_MAX)
		|| str == "+inf" || str == "-inf" || str == "nan" )
		intOverflow = true;
	if (!intOverflow) {
		if (isascii(nb)) {
			if (isprint(nb))
				std::cout << " char: " << static_cast<char>(nb) << std::endl;
			else
				std::cout << " char: Non printable" << std::endl;
		}
		else 
			std::cout << " char: Impossible convertion" << std::endl;
		std::cout << " int: " << static_cast<int>(nb) << std::endl;
		std::cout << " float: " << printPointNb(static_cast<float>(nb)) << "f" << std::endl;
		std::cout << " double: " << printPointNb(nb) << std::endl;
	}
	else {
		std::cout << " char: Impossible convertion" << std::endl;
		std::cout << " int: Impossible convertion" << std::endl;
		std::cout << " float: " << printPointNb(static_cast<float>(nb)) << "f" << std::endl;
		std::cout << " double: " << printPointNb(nb) << std::endl;
	}
}

void	ScalarConverter::convert(const std::string input) {
	std::cout << std::fixed;
	switch (getType(input))
	{
	case CHAR:
		convertChar(input[0]);
		break;
	case INT:
		convertInt(input);
		break;
	case FLOAT:
		convertFloat(input);
		break;
	case DOUBLE:
		convertDouble(input);
		break;	
	default:
			std::cout << "  char: " << "Impossible" << std::endl;
			std::cout << "   int: " << "Impossible" << std::endl;
			std::cout << " float: " << "Impossible" << std::endl;
			std::cout << "double: " << "Impossible" << std::endl;
		break;
	}
}
