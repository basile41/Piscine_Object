#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account
{
public:
	Account(size_t id, size_t initial_deposit = 0);
	Account(const Account &other);
	~Account();
	Account &operator=(const Account &other);

	const size_t & getValue() const;
	const size_t & getLoanedValue() const;

	void	deposit(size_t deposit_value);
	bool	withdraw(size_t withdraw_value);
	void	giveLoan(size_t loan_value);
	bool	repayLoan(size_t repay_value);

	friend std::ostream & operator<<(std::ostream& os, const Account& account);

private:
	Account();
	
	const size_t	_id;
	size_t			_value;
	size_t 			_loaned_value;
};

std::ostream & operator<<(std::ostream& os, const Account& account);

#endif /* ACCOUNT_HPP */
