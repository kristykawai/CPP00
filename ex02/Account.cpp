/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawai <kawai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:07:33 by kawai             #+#    #+#             */
/*   Updated: 2024/03/31 16:48:32 by kawai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Static member variables initialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor
//[19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), 
										_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) 
{
	++_nbAccounts;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// Destructor
//[19920104_091532] index:0;amount:47;closed
Account::~Account() 
{
	--_nbAccounts;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Static member function definitions
int	Account::getNbAccounts()
{
	return _nbAccounts;
}
int	Account::getTotalAmount()
{
	return _totalAmount;
}
int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit )
{
	++_nbDeposits;
	++_totalNbDeposits;
	_totalAmount += deposit;
	_amount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << 
		(_amount - deposit) << ";deposit:" << deposit << ";amount:" << _amount <<
		";nb_deposits:" << _nbDeposits << std::endl;
}

//[19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > _amount)
	{		
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << 
		(_amount) << ";withdrawal:refused" << std::endl;
		return(false);
	}
	++_nbWithdrawals;
	++_totalNbWithdrawals;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << 
		(_amount + withdrawal) << ";withdrawal:" << withdrawal << ";amount:" << _amount <<
		";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return(true);
}

int		Account::checkAmount( void ) const
{
	return _amount;

}

//[19920104_091532] index:5;amount:23;deposits:1;withdrawals:0
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << 
		_amount << ";deposits:" << _nbDeposits << ";withdrawls:" << _nbWithdrawals << std::endl;
}

//format [YYYYMMDD_HHMMSS]
void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(nullptr);
	std::tm* timeInfo = std::localtime(&now);

	std::cout	<< "[" << (timeInfo-> tm_year + 1900) 
				<< std::setw(2) << std::setfill('0') << (timeInfo->tm_mon + 1)
				<< std::setw(2) << std::setfill('0') << (timeInfo->tm_mday) << "_"
				<< std::setw(2) << std::setfill('0') << (timeInfo->tm_hour)
				<< std::setw(2) << std::setfill('0') << (timeInfo->tm_min)
				<< std::setw(2) << std::setfill('0') << (timeInfo->tm_sec) << "] "; 
}
