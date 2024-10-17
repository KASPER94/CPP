/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:03:26 by peanut            #+#    #+#             */
/*   Updated: 2024/10/17 19:32:39 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
// #include "BitcoinExchange.cpp"

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

std::map<int, std::string>	split_trim(std::string str, char c) {
	std::map<int, std::string>	split;
	std::string					sub;
	int							i = 0;

	int end = str.find(c);
	while (end != -1) {
		sub = str.substr(0, end);
		ltrim(sub);
		rtrim(sub);
		split.insert(std::pair<int, std::string>(i++, sub));
		str.erase(str.begin(), str.begin() + end + 1);
		end = str.find(c);
	}
	ltrim(str);
	rtrim(str);
	split.insert(std::pair<int, std::string>(i++, str));
	return (split);
}

void	BitcoinExchange::printTop() {
	std::cout <<\
		"╔════════════════╦═════════════════╦═══════════════════╦══════════════════════════╗" \
		<< std::endl;
	std::cout << "║"   "      DATE      "  "║" "   AMOUNT(BTC)   " \
		"║"  "     AMOUNT($)     " "║"  "         DB ENTRY" \
		<< "         ║"  << std::endl;
	std::cout << \
		"╠════════════════╬═════════════════╬═══════════════════╬══════════════════════════╣" \
		<< std::endl;
}

void	BitcoinExchange::printBottom() {
	std::cout << \
		"╚════════════════╩═════════════════╩═══════════════════╩══════════════════════════╝" \
		<< std::endl;
}

void	BitcoinExchange::printLineDateBtcError(std::string date,
		std::string btc, int type) {
	std::cout << "║ ";
	std::cout.width(14);
	std::cout << std::left << date << std::right << " ║ ";
	std::cout.width(17);
	std::cout <<  "₿ " + btc << " ║ ";
	std::cout << "Error: both       ║ ";
	if (type == 1)
		std::cout << "Invalide number          ║" << std::endl;
	else if (type == 2)
		std::cout << "Negative number          ║" << std::endl;
	else
		std::cout << "Too large number         ║" << std::endl;
}

void	BitcoinExchange::printLinePriceError(std::string date,
		std::string btc, int type) {
	std::cout << "║ ";
	std::cout.width(14);
	std::cout << std::left << date << std::right << " ║ ";
	std::cout.width(17);
	std::cout <<  "₿ " + btc << " ║ ";
	std::cout << "Error: Price       ║ ";
	if (type == 1)
		std::cout << "Invalide number          ║" << std::endl;
	else if (type == 2)
		std::cout << "Negative number          ║" << std::endl;
	else
		std::cout << "Too large number         ║" << std::endl;
}

std::string converTime(long date) {
	struct tm	ts;
    char		buf[20];

	ts = *localtime(&date);
	strftime(buf, sizeof(buf), "%Y-%m-%d", &ts);
	return (buf);

}

std::string dtoa(double price) {
	std::ostringstream	s;
	std::string			str;

	s << std::setprecision(2) << std::fixed << price;
	str = s.str();
	str = str.erase(str.find_last_not_of('0') + 1);
	if (str[str.length() - 1] == '.')
		str += "0";
	return (str);

}

void	BitcoinExchange::printLine(std::string date,
		std::string btc, long first, double second) {
	std::cout << "║ " << date <<  "     ║ " ;
	std::cout.width(17);
	std::cout <<  "₿ " + btc <<  " ║ ";
	std::cout.width(17);
	std::cout << "$ " + dtoa(second * std::atof(btc.c_str())) << " ║ ";
	std::cout << converTime(first);
	std::cout.width(14);
	std::cout << "$ " + dtoa(second) << " ║" << std::endl;

}

void BitcoinExchange::printLineDateError(std::string date,
		std::string btc, int type) {
	std::cout << "║ ";
	std::cout.width(14);
	std::cout << std::left << date << std::right << " ║ ";
	std::cout.width(17);
	std::cout <<  "₿ " + btc << " ║ ";
	std::cout << "Error: Date       ║ ";
	if (type == 1)
		std::cout << "Bitcoin did not exist         ║" << std::endl;
	else
		std::cout << "                         ║" << std::endl;	
}

void	BitcoinExchange::printErrorLine(int line) {
	std::cout << "║                ║                 ║ ";
	std::cout << "Error: line ";
	std::cout.width(5);
	std::cout << std::left << line << std::right << " ║ ";
	std::cout << "Wrong format             ║" << std::endl;
}

bool checkPrice(std::string price, int &err_code) {
	double dprice;
	int	point = 0;
	int i = 0;

	if (price[0] == '-' || price[0] == '+')
		i++;
	while (price[i]) {
		if (std::isdigit(price[i])) {
			i++;
		}
		else if (price[i] == '.') {
			if (point == 0)
				i++;
			else {
				err_code = 1;
				return (false);
			}
		}
		else {
			err_code = 1;
			return (false);
		}
	}
	dprice = atof(price.c_str());
	if (dprice < 0)
		err_code = 2;
	else if (dprice > 1000)
		err_code = 3;
	return (dprice);
}

bool	BitcoinExchange::parseInputLine(std::string input) {
	long		timestamp;
	std::map<int, std::string>	split;
	static int					line_num = 1;
	int							err_code = 0;

	split = split_trim(input, '|');
	if (split.size() != 2 && (split.size() == 1 && split[0] != "")) {
		this->printErrorLine(line_num);
		return (false);
	}
	if (split.size() == 1 && split[0] != "")
		return (false);
	timestamp = this->getTimestamp(split[0]);
	checkPrice(split[1], err_code);
	if (err_code != 0 || timestamp == -1){
		this->printLineDateBtcError(split[0], split[1], err_code);
	}
	else if (timestamp == -1) {
		this->printLineDateError(split[0], split[1], 0);
	}
	else if (err_code != 0) {
		this->printLinePriceError(split[0], split[1], err_code);
	}
	else {
		std::map<long, double>::iterator low;
		low = this->_db.lower_bound(timestamp);
    	if (low->first != timestamp && low == this->_db.begin())
			this->printLineDateError(split[0], split[1], 1);
		else if (low->first != timestamp){
			low--;
			this->printLine(split[0], split[1], low->first, low->second);
		} else
			this->printLine(split[0], split[1], low->first, low->second);
	}
	return (line_num++, true);
}

bool	BitcoinExchange::convert(const std::string input_db) {
	std::ifstream				input;
	std::string					line;
	std::map<int, std::string>	split;

	input.open(input_db.c_str());
	if (!input.good()) {
		input.close();
		return (false);
	}
	std::getline(input, line);
	split = split_trim(line, '|');
	if (split.size() != 2 || (split[0] != "date" || split[1] != "value")) {
		throw InvalidInput();
	}
	printTop();
	for (; std::getline(input, line);) {
		this->parseInputLine(line);
	}
	printBottom();
	return (true);
}
