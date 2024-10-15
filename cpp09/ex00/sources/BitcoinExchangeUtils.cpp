/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:03:26 by peanut            #+#    #+#             */
/*   Updated: 2024/10/15 15:47:29 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	rtrim(std::string &s) {
	int	i = s.length() - 1;

	while (std::isspace(s[i]))
		i--;
    s = s.substr(0, i + 1);
}

void	ltrim(std::string &s) {
	int	i = s.length() - 1;

	while (std::isspace(s[i]))
		i++;
    s = s.substr(0, i + 1);
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
	std::cout << split.end()->first << std::endl;
	return (true);
}
