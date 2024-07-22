#include "Bank.hpp"
#include <cassert>

Account::Account(size_t id, size_t initial_deposit)
: _id(id), _value(initial_deposit), _loaned_value(0)
{
}

Account::Account(const Account &other)
: _id(other._id)
{
	*this = other;
}

Account::~Account()
{
}

Account &Account::operator=(const Account &other)
{
	if (this != &other)
	{
		_value = other._value;
		_loaned_value = other._loaned_value;
	}
	return *this;
}

const size_t & Account::getValue() const
{
	return _value;
}

const size_t & Account::getLoanedValue() const
{
	return _loaned_value;
}

void Account::deposit(size_t deposit_value)
{
	_value += deposit_value;
	std::cerr << "Deposited " << deposit_value << " to account " << _id << std::endl;
}

bool Account::withdraw(size_t withdraw_value)
{
	if (_value >= withdraw_value)
	{
		_value -= withdraw_value;
		std::cerr << "Withdrew " << withdraw_value << " from account " << _id << std::endl;
		return true;
	}
	else
	{
		std::cerr << "Insufficient funds to withdraw " << withdraw_value << " from account " << _id << std::endl;
		return false;
	}
}

void Account::giveLoan(size_t loan_value)
{
	_value += loan_value;
	_loaned_value += loan_value;
	std::cerr << "Gave loan of " << loan_value << " to account " << _id << std::endl;
}

bool Account::repayLoan(size_t repay_value)
{
	if (_loaned_value < repay_value)
	{
		std::cerr << "Cannot repay loan of " << repay_value << " to account " << _id << " (loaned value : " << _loaned_value << ")" << std::endl;
		return false;
	}
	if (_value < repay_value)
	{
		std::cerr << "Insufficient funds to repay loan of " << repay_value << " to account " << _id << std::endl;
		return false;
	}
	_value -= repay_value;
	_loaned_value -= repay_value;
	std::cerr << "Repaid loan of " << repay_value << " to account " << _id << std::endl;
	return true;
}

std::ostream & operator<<(std::ostream& os, const Account& account)
{
	os << "Value = " << account.getValue() << "; Loanned = " << account._loaned_value;
	return os;
}
