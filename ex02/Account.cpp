#include "Account.hpp"


Account::Account(int deposit)
{
	makeDeposit(deposit);
}

void Account::makeDeposit(int deposit)
{
}

bool Account::makeWithdrawal(int withraw)
{
	return false;
}

int Account::checkAmount()  const {
	return 0;
}

void Account::displayStatus() const {

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
