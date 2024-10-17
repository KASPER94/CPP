/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:03:26 by peanut            #+#    #+#             */
/*   Updated: 2024/10/16 23:12:42 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _dataValid(false) {
	try {
		checkDataBase();
	}
    catch (const noDataInDir &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const InvalidData &e) {
        std::cerr << e.what() << std::endl;
    }
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

bool checkLeapYear(std::tm tm){
	if (tm.tm_year % 4 == 0) {
		if (tm.tm_year % 100 == 0 && tm.tm_year % 400 == 0) {
			return (true);
		}
	}
	return (false);
}

long getTimestamp(std::string line) {
	std::tm		tm = {};
	std::time_t time;
	int			year = 0;
	int			month = 0;
	int			day = 0;

	if (line.empty()) {
		return (-1);
	}
	if (strptime(line.c_str(), "%Y-%m-%d", &tm) == NULL)
		return (-1);
	getDateParts(line, year, month, day);
	if (tm.tm_year + 1900 != year || tm.tm_mon + 1 != month || tm.tm_mday != day )
		return (-1);
	if (year < 1900 || year > 3000)
		return (-1);
	if (month == 2) {
		if ((checkLeapYear(tm) && tm.tm_mday > 28) || (!checkLeapYear(tm) && tm.tm_mday > 29) )
			return (-1);
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (-1);
    tm.tm_isdst = -1;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
	time = std::mktime(&tm);
	return (time);
}

bool BitcoinExchange::parsingLine(const std::string line) {
	long	timestamp;
	double	price;

	if (line.length() < 12) {
		return (false);
	}
	timestamp = getTimestamp(line.substr(0, line.find(",")));
	if (timestamp == -1)
		return (false);
	int start = line.find(",");
	price = std::atof(line.substr((start + 1), line.size()).c_str());
	this->_db.insert(std::pair<long, double>(timestamp, price));
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

const char *BitcoinExchange::noDataInDir::what() const throw() {
    return ((char*)"No data file in the directory !");
}

const char *BitcoinExchange::InvalidData::what() const throw() {
	return ((char*)"Data from the file is not well formated !");
}

const char *BitcoinExchange::InvalidInput::what() const throw() {
	return ((char*)"The input is not well formated !");
}