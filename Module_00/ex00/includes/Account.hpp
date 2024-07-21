#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account
{
public:
	Account();
	Account(const Account &other);
	Account &operator=(const Account &other);
	~Account();

	int		getValue() const;
	void	setValue(int value);

private:
	const int	_id;
	int			_value;
};

#endif /* ACCOUNT_HPP */
