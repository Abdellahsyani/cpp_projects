#include "Account.hpp"


Account::Account(int deposit) :
	_accountIndex(_nbAccounts),
	_amount(0),
	_nbDeposits(0),
	_nbWithrawals(0) 
{
	_accountIndex++;
	_nbAccounts += _accountIndex;
//	makeDeposit(deposit);
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits += _nbDeposits;
	_amount += deposit;
	_totalAmount += _amount;
}

bool Account::makeWithdrawal(int withraw)
{
	if (withraw >= _amount)
	{
		std::count << "Your balance is not enough try again" << std::endl;
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
	std::cout << "[]" << "Index: " << _accountIndex << "amount: " << _amount << "deposits: " << _nbDeposits << "withrawals: " << _nbWithrawals << std::endl;
}

int Account::getNbAccounts() { return 0;};
int Account::getTotalAmount() { return 0;};
int Account::getNbDeposits() {return 0;};
int Account::getNbWithdrawals() { return 0;};
void Account::displayAccountsInfos() {};

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
