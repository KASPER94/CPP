/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:03:26 by peanut            #+#    #+#             */
/*   Updated: 2024/10/14 12:48:34 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _dataValid(false) {
	checkDataBase();
}

BitcoinExchange::~BitcoinExchange() {
	this->_db.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
	*this = cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs){
	this->_db = rhs._db;
	return (*this);
}

void	getDateParts(std::string date, int &year, int &month, int &days) {

	int	end = date.find("-");
	year = std::atoi(date.substr(0, end).c_str());
	date.erase(0, end + 1);
	end = date.find("-");
	month = std::atoi(date.substr(0, end).c_str());
	date.erase(0, end + 1);
	end = date.find(",");
	days = std::atoi(date.substr(0, end).c_str());
	date.erase(0, end + 1);
}

long getTimestamp(std::string line) {
	std::tm		tm;
	// std::time_t t;
	int			year = 0;
	int			month = 0;
	int			day = 0;

	if (line.empty()) {
		return (-1);
	}
	getDateParts(line, year, month, day);
	if (strptime(line.c_str(), "%Y-%m-%d", &tm) == NULL)
		std::cout << "galere" << std::endl;
	return (0);
}

bool parsingLine(const std::string line) {
	long	timestamp;

    if (line.length() < 12) {
        return (false);
	}
	timestamp = getTimestamp(line.substr(0, line.find(",")));
	if (timestamp == -1)
		return (false);
	return (true);
}

void BitcoinExchange::checkDataBase(void) {
    std::ifstream data;
    std::string   line;

    data.open("db/data.csv");
    if (data.good()) {
        this->_dataValid = true;
        for (; std::getline(data, line) && this->_dataValid;) {
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
