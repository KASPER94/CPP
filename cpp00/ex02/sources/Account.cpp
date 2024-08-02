/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:05:57 by skapersk          #+#    #+#             */
/*   Updated: 2024/08/01 00:55:45 by skapersk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int deposit)
{
	this->_amount = deposit;
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index : " << this->_accountIndex << ";";
	std::cout << "amout : " << this->checkAmount() << "; created" << std::endl;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index : " << this->_accountIndex << ";";
	std::cout << "amount : " << this->checkAmount() << "; closed" << std::endl;
	return ;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);

}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
	time_t	now;
	tm		*t;

	now = time(0);
	t = localtime(&now);
	std::cout << "[" << std::setfill('0') << 1900 + t->tm_year;
	std::cout << std::setw(2) << t->tm_mon + 1;
	std::cout << std::setw(2) << t->tm_mday << "_";
	std::cout << std::setw(2) << t->tm_hour;
	std::cout << std::setw(2) << t->tm_min;
	std::cout << std::setw(2) << t->tm_sec << "]";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts : " << getNbAccounts() << ";";
	std::cout << "total : " << getTotalAmount() << ";";
	std::cout << "deposits : " << getNbDeposits() << ";";
	std::cout << "withdrawals : " << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index : " << this->_accountIndex << ";";
	std::cout << "amount : " << this->checkAmount() << ";";
	std::cout << "deposit : " << deposit << ";";
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	this->_nbDeposits++;
	std::cout << "amout : " << this->checkAmount() << ";";
	std::cout << "nb deposits : " << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index : " << this->_accountIndex << ";";
	std::cout << "amount : " << this->checkAmount() << ";";
	if (this->checkAmount() < withdrawal)
	{
		std::cout << "withdrawal : refused" << std::endl;
		return (false); 
	}
	else
	{
		std::cout << "withdrawal : " << withdrawal << ";";
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		std::cout << "amout : " << this->checkAmount() << ";";
		std::cout << "nb withdrawal : " << this->_nbWithdrawals << std::endl;	
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index : " << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;

}
