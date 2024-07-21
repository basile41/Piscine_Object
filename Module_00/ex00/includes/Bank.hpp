#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <map>

#include "Account.hpp"


class Bank
{
public:
	class Account;
	
	Bank();
	Bank(const Bank &other);
	Bank &operator=(const Bank &other);
	~Bank();

	int	&	getLiquidity() const;

private:
	int	_liquidity;
};

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);


#endif /* BANK_HPP */
