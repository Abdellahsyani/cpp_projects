#include "Account.hpp"
#include <ctime>
#include <iostream>


Account::Account(int deposit) :
	_accountIndex(_nbAccounts),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0) 
{
	_accountIndex += 1;
	_nbAccounts++;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits += _nbDeposits;
	_amount += deposit;
	_totalAmount += _amount;
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
		std::cout << "Your balance is not enough try again" << std::endl;
		return false;
	}
	_amount -= withraw;
	return true;
}

int Account::checkAmount()  const {
	std::cout << "Your balance: " << _amount << std::endl;
	return 0;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "Index: " << _accountIndex
		<< ";" << "amount: " << _amount
		<< ";" << "deposits: " << _nbDeposits
		<< ";" << "withrawals: " << _nbWithdrawals << std::endl;
}


void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
};

Account::~Account() {
	std::cout << "This is closed" << std::endl;
};

int Account::getNbAccounts() { return 0;};
int Account::getTotalAmount() { return 0;};
int Account::getNbDeposits() {return 0;};
int Account::getNbWithdrawals() { return 0;};

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
