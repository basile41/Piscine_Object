#include "Bank.hpp"
#include <cassert>

Account::Account(int id, int initial_deposit) : _id(id), _value(initial_deposit)
{
	std::cerr << "Created account " << _id << std::endl;
}

Account::~Account()
{
	std::cerr << "Destroyed account " << _id << std::endl;
}

const int & Account::getValue() const
{
	return _value;
}

int Account::deposit(int deposit_value)
{
	assert(deposit_value >= 0 && "Deposit value cannot be negative");
	_value += deposit_value;
	std::cerr << "Deposited " << deposit_value << " to account " << _id << std::endl;
	return _value;
}

bool Account::withdraw(int withdraw_value)
{
	assert(withdraw_value >= 0 && "Withdraw value cannot be negative");
	if (_value < withdraw_value)
	{
		std::cerr << "Withdrawal refused: not enough money" << std::endl;
		return false;
	}
	_value -= withdraw_value;
	std::cerr << "Withdrew " << withdraw_value << " from account " << _id << std::endl;
	return true;
}

std::ostream& operator << (std::ostream& os, const Account& account)
{
	os << "Account " << account._id << " : " << account._value;
	return os;
}
