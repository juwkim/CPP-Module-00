/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 04:14:33 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/23 04:43:56 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) :
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_accountIndex = Account::_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << checkAmount() << ';';
	std::cout << "created" << '\n';
}

Account::Account(int initial_deposit) :
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_accountIndex = Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << checkAmount() << ';';
	std::cout << "created" << '\n';
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "closed" << '\n';
}

void	Account::_displayTimestamp(void)
{
	time_t		rawtime;
	struct tm	*timeinfo;
	char		buf[100];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buf, 100, "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << buf;
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ';';
	std::cout << "total:" << Account::_totalAmount << ';';
	std::cout << "deposits:" << Account::_totalNbDeposits << ';';
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << '\n';
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << checkAmount() << ';';
	std::cout << "deposit:" << deposit << ';';
	_amount += deposit;
	_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << checkAmount() << ';';
	std::cout << "nb_deposits:" << _nbDeposits << '\n';
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << checkAmount() << ';';
	std::cout << "withdrawal:";
	if (checkAmount() < withdrawal) {
		std::cout << "refused" << '\n';
		return (false);
	}
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << "amount:" << checkAmount() << ';';
	std::cout << "nb_withdrawals:" << _nbWithdrawals << '\n';
	return (true);
}

int		Account::checkAmount(void) const {
	return _amount;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << checkAmount() << ';';
	std::cout << "deposits:" << _nbDeposits << ';';
	std::cout << "withdrawals:" << _nbWithdrawals << '\n';
}
