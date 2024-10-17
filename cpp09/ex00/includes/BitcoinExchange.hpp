/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/17 19:10:37 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <stdlib.h>
# include <fstream>
# include <ctime>
# include <map>

class BitcoinExchange{
    private:
        bool _dataValid;
		std::map<long, double>	_db;
        bool    parseInputLine(std::string input);
        long    getTimestamp(std::string line);
        void    printErrorLine(int line);
        void    printLineDateBtcError(std::string date, std::string btc, int type);
        void    printLineDateError(std::string date, std::string btc, int type);
        void    printLinePriceError(std::string date, std::string btc, int type);
        void    printLine(std::string date, std::string btc, long first, double second);
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &cpy);

        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        class noDataInDir: std::exception {
            public:
                const char* what() const throw();
        };
		class InvalidData: std::exception {
			public:
				const char* what() const throw();
		};
        class InvalidInput: std::exception {
			public:
				const char* what() const throw();
		};
        void checkDataBase();
		bool parsingLine(const std::string line);
		bool convert(const std::string input_db);
        void printTop();
        void printBottom();
};

#endif
