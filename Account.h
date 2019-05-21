#include <iostream>
#include <string>
#include <iomanip>      
#include <stdlib.h>
#include <cstdlib>
using namespace std;
class Account
{
public:
	Account();
	Account(int balance); 
	void Add(int money); 
	void SetBalance(int money);
	void Withdraw(int money); 
	double GetBalance();
private:
	int balance; 
}; 
