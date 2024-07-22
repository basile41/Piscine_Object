#include "Bank.hpp"

Bank::Bank(size_t initial_liquidity)
: _liquidity(initial_liquidity), _next_id(0), _accounts(), _deposit_fee(0.05)
{
}

Bank::~Bank()
{
}

const size_t & Bank::getLiquidity() const
{
	return _liquidity;
}

const Account & Bank::getAccount(size_t id) const
{
	std::map<size_t, Account>::const_iterator it = _accounts.find(id);
	if (it == _accounts.end())
	{
		std::cerr << "Account " << id << " not found" << std::endl;
	}
	return it->second;
}

size_t Bank::createAccount(size_t initial_deposit)
{
	_accounts.insert(std::make_pair(_next_id, Account(_next_id, initial_deposit)));
	std::cerr << "New account created : id : " << _next_id << " value : " << initial_deposit << std::endl;
	_liquidity += initial_deposit;
	return _next_id++;
}

bool Bank::closeAccount(size_t id)
{
	std::map<size_t, Account>::iterator it = _accounts.find(id);
	if (it == _accounts.end())
	{
		std::cerr << "Account " << id << " not found" << std::endl;
		return false;
	}
	if (it->second.getLoanedValue() > 0)
	{
		std::cerr << "Account " << id << " has a loan of " << it->second.getLoanedValue() << std::endl;
		return false;
	}
	if (it->second.withdraw(it->second.getValue()))
	{
		_accounts.erase(it);
		std::cerr << "Account " << id << " closed" << std::endl;
		return true;
	}
	return false;
}

void Bank::deposit(size_t id, size_t deposit_value)
{
	static const float multiplier = 1 - _deposit_fee;

	std::map<size_t, Account>::iterator it = _accounts.find(id);
	if (it == _accounts.end())
	{
		std::cerr << "Account " << id << " not found" << std::endl;
		return;
	}
	it->second.deposit(deposit_value * multiplier);
	_liquidity += deposit_value;
}

bool Bank::withdraw(size_t id, size_t withdraw_value)
{

	std::map<size_t, Account>::iterator it = _accounts.find(id);
	if (it == _accounts.end())
	{
		std::cerr << "Account " << id << " not found" << std::endl;
		return false;
	}
	if (it->second.withdraw(withdraw_value))
	{
		_liquidity -= withdraw_value;
		return true;
	}
	return false;
}

bool Bank::transfer(size_t from_id, size_t to_id, size_t transfer_value)
{
	std::map<size_t, Account>::iterator it_to = _accounts.find(to_id);
	if (it_to == _accounts.end())
	{
		std::cerr << "Account " << to_id << " not found" << std::endl;
		return false;
	}
	if (withdraw(from_id, transfer_value))
	{
		deposit(to_id, transfer_value);
		return true;
	}
	return false;
}

void Bank::giveLoan(size_t id, size_t loan_value)
{
	std::map<size_t, Account>::iterator it = _accounts.find(id);
	if (it == _accounts.end())
	{
		std::cerr << "Account " << id << " not found" << std::endl;
		return;
	}
	it->second.giveLoan(loan_value);
}

bool Bank::repayLoan(size_t id, size_t repay_value)
{
	std::map<size_t, Account>::iterator it = _accounts.find(id);
	if (it == _accounts.end())
	{
		std::cerr << "Account " << id << " not found" << std::endl;
		return false;
	}
	if (it->second.repayLoan(repay_value))
	{
		return true;
	}
	return false;
}

std::ostream& operator << (std::ostream& os, const Bank& bank)
{
	os << "Bank liquidity : " << bank.getLiquidity() << std::endl;
	std::map<size_t, Account>::const_iterator it = bank._accounts.begin();
	while (it != bank._accounts.end())
	{
		os << "Account " << it->first << " : " << it->second << std::endl;
		++it;
	}
	return os;
}
