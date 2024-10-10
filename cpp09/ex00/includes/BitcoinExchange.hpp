/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peanut <peanut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:24 by skapersk          #+#    #+#             */
/*   Updated: 2024/10/10 14:26:03 by peanut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>


class BitcoinExchange{
    private:
        bool _dataValid;
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
};

#endif