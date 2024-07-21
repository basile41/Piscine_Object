#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account
{
public:
	Account(int id, int initial_deposit = 0);
	~Account();

	const int & getValue() const;

	int	deposit(int deposit_value);
	bool withdraw(int withdraw_value);

	friend std::ostream& operator << (std::ostream& os, const Account& account);

private:
	Account();
	Account(const Account &other);
	Account &operator=(const Account &other);
	
	const int	_id;
	int			_value;
};

std::ostream& operator << (std::ostream& os, const Account& account);

#endif /* ACCOUNT_HPP */
