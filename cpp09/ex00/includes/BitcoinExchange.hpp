/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/14 15:28:24 by skapersk         ###   ########.fr       */
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
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &cpy);

        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        class noDataInDir: std::exception {
            public:
                const char* what() const throw();
        };
        void checkDataBase();
		bool parsingLine(const std::string line);
};

#endif
