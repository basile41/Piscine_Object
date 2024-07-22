#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <map>

#include "Account.hpp"


class Bank
{
public:
	
	Bank(size_t initial_liquidity = 0);
	~Bank();

	const size_t &	getLiquidity() const;
	const Account &	getAccount(size_t id) const;

	size_t	createAccount(size_t initial_deposit = 0);
	bool	closeAccount(size_t id);

	void	deposit(size_t id, size_t deposit_value);
	bool	withdraw(size_t id, size_t withdraw_value);
	bool	transfer(size_t from_id, size_t to_id, size_t transfer_value);
	void	giveLoan(size_t id, size_t loan_value);
	bool	repayLoan(size_t id, size_t repay_value);

	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);

private:
	Bank(const Bank &other);
	Bank &operator=(const Bank &other);

	size_t						_liquidity;
	size_t						_next_id;
	std::map<size_t, Account>	_accounts;
	float 						_deposit_fee;
};

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);


#endif /* BANK_HPP */
