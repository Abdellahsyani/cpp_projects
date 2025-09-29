#include "Account.hpp"
#include <ctime>
#include <iostream>


Account::Account(int deposit) :
	_accountIndex(_nbAccounts),
	_amount(deposit),
	_nbDeposits(0),
	_nbWithdrawals(0) 
{
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:"<< _amount << ";"
		<< "created" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits += _nbDeposits;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:"<< _amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount + deposit << ";"
		<< "nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
}

void Account::_displayTimestamp(void) {
    std::time_t now = std::time(nullptr);
    std::tm* local = std::localtime(&now);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", local);

    std::cout << buffer << " ";
}

bool Account::makeWithdrawal(int withraw)
{
	if (withraw >= _amount)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";"
			<< "p_amount:"<< _amount << ";"
			<< "withdrawal:refused" << std::endl;
		return false;
	}
	_nbWithdrawals++;
	_totalNbWithdrawals += _nbWithdrawals;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:"<< _amount << ";"
		<< "withdrawal:" << withraw << ";"
		<< "amount:" << _amount - withraw << ";"
		<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withraw;
	_totalAmount -= withraw;
	return true;
}

int Account::checkAmount()  const {
	std::cout << "Your balance: " << _amount << std::endl;
	return 0;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";" << "amount:" << _amount
		<< ";" << "deposits:" << _nbDeposits
		<< ";" << "withdrawals:" << _nbWithdrawals << std::endl;
}


void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << std::endl;
};

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";" << "amount:" << _amount
		<< ";" << "closed" << std::endl;
};

int Account::getNbAccounts() { return _nbAccounts;};
int Account::getTotalAmount() { return _totalAmount;};
int Account::getNbDeposits() {return _totalNbDeposits;};
int Account::getNbWithdrawals() { return _totalNbWithdrawals;};

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
