// #include "Account.hpp"

// void testAccount()
// {
// 	try
// 	{
// 		Account account(42, 100);
// 		std::cout << account << std::endl;
// 		account.deposit(50);
// 		std::cout << account << std::endl;
// 		account.withdraw(150);
// 		std::cout << account << std::endl;
// 		account.withdraw(50);
// 		std::cout << account << std::endl;
// 		// account.deposit(-50);
// 		// std::cout << account << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
	
// }

#include "Bank.hpp"

int main()
{
	Bank bank(1000);


	size_t toto_account_id = bank.createAccount();
	std::cout << bank << std::endl;

	bank.deposit(toto_account_id, 100);
	std::cout << bank << std::endl;

	bank.withdraw(toto_account_id, 100);
	std::cout << bank << std::endl;
	bank.withdraw(toto_account_id, 95);
	std::cout << bank << std::endl;

	size_t bob_account_id = bank.createAccount(500);
	std::cout << bank << std::endl;

	bank.giveLoan(toto_account_id, 1000);
	std::cout << bank << std::endl;

	bank.withdraw(toto_account_id, 1000);
	std::cout << bank << std::endl;

	bank.deposit(toto_account_id, 1000);
	std::cout << bank << std::endl;

	bank.repayLoan(toto_account_id, 1000);
	std::cout << bank << std::endl;

	bank.deposit(toto_account_id, 100);
	std::cout << bank << std::endl;

	bank.repayLoan(toto_account_id, 1000);
	std::cout << bank << std::endl;

	bank.transfer(bob_account_id, toto_account_id, 200);
	std::cout << bank << std::endl;

	return 0;
}
