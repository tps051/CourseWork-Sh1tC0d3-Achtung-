#include "Account.h"
const int PENALTY_FEE = 5.00;
Account::Account() {
	balance = 0; 
}
Account::Account(int money)	{
	balance = money;																				
}
void Account::SetBalance(int money) {
	balance = money;
}
void Account::Add(int money)	{
	balance += money;																				 
}
void Account::Withdraw(int money)	{
	if (money > balance)
		balance += PENALTY_FEE;
	else
		balance -= money;
}
double Account::GetBalance()	{
	return balance;
}