#include "Account.hpp"

t User;

Account::Account(int deposit, int index, int amount, int nbDeposits, int nbWithrawals) 
	makeDeposit(deposit);
	_accountIndex = index;
	_amount = amount;
	_nbDeposits = nbDeposits;
	_nbWithrawals = nbWithrawals;
};

t::makeDeposit(int deposit)
{
	Account::_nbAccounts
}

int Account::_nbAccounts = 0;
int Account::_totAlAmount = 0;
int Account::_totAlNbDeposits = 0;
int Account::_totAlNbWithrAwAls = 0;
