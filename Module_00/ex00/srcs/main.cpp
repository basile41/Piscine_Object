#include "Account.hpp"

void testAccount()
{
	Account account(42, 100);
	std::cout << account << std::endl;
	account.deposit(50);
	std::cout << account << std::endl;
	account.withdraw(150);
	std::cout << account << std::endl;
	account.withdraw(50);
	std::cout << account << std::endl;
	account.deposit(-50);
	std::cout << account << std::endl;
}

int main()
{
	testAccount();
	return 0;
}
