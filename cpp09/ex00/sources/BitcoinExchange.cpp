/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:03:26 by peanut            #+#    #+#             */
/*   Updated: 2024/10/11 15:49:21 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _dataValid(false) {

}

BitcoinExchange::~BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs){

}

long getTimestamp(std::string line) {

}

bool parsingLine(const std::string line) {
	long	timestamp;

    if (line.length() != 12)
        return (false);
	timestamp = getTimestamp(line.substr(0, line.find(",")));
	if (timestamp == -1)
		return (false);

}

void BitcoinExchange::checkDataBase(void) {
    std::ifstream data;
    std::string   line;

    data.open("/db/data.csv");
    if (data.good()) {
        this->_dataValid = true;
        for (; std::getline(data, line) && this->_dataValid) {
            if (line == "date,exchange_rate")
                continue ;
            if (!parsingLine(line))
                this->_dataValid = false;
        }
    }
    else {
        data.close();
        throw noDataInDir();
    }
    data.close();
}

const char *BitcoinExchange::noDataInDir::what() const throw() {
    return ((char*)"No data file in the directory !");
}
