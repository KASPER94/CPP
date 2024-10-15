/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:03:26 by peanut            #+#    #+#             */
/*   Updated: 2024/10/15 15:21:11 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::checkDataBase(void) {
    std::ifstream data;
    std::string   line;

    data.open("db/data.csv");
    if (data.good()) {
        this->_dataValid = true;
        for (; std::getline(data, line) && this->_dataValid;) {
            if (line == "date,exchange_rate")
                continue ;
            if (!parsingLine(line)) {
                this->_dataValid = false;
				data.close();
				throw InvalidData();
			}
        }
    }
    else {
        data.close();
        throw noDataInDir();
    }
    data.close();
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
	std::getline(input_db, line);
}
