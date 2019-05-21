#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
#include "Client.h"
#include <locale.h>
#include <time.h>
#include <random>
#include <malloc.h>
#include <cstdio>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;
void deposit(int, string);
void withdraw(int, string);
void transfer(int, string);
void printBalances();
Account savings, debet;


void deposit(int amount, string account) {
	if (account == "S" || account == "s") {
		savings.Add(amount);
	}
	else {
		debet.Add(amount);
	}
}

void withdraw(int amount, string account) {
	if (account == "S" || account == "s") {
		savings.Withdraw(amount);
	}
	else {
		debet.Withdraw(amount);
	}
}
void transfer(int amount, string account) 
{
	if (account == "S" || account == "s") {
		savings.Withdraw(amount);
		debet.Add(amount);
	}
	else {
		debet.Withdraw(amount);
		savings.Add(amount);
	}
}
void printBalances() {
	cout << "The current balance in savings is: " << savings.GetBalance() << endl;
	cout << "The current balance in debet is: " << debet.GetBalance() << endl << endl;
}
int cnt_digits(int num) { 
	return (num /= 10) ? 1 + cnt_digits(num) : 1;
}
struct ClientData{
	char Name[15];
	char Sname[20];
	char num[10];
};
int main()
{
	srand(time(NULL));
	ClientData *Arr;
	Arr = (ClientData*)malloc(sizeof(ClientData));
	FILE *PB, *PB2;
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
    string accountChoice;
	char s[80], *p;
    int transaction = 0;
	char name[10], sname[12], num[9], balanceS[8], balanceC[8];
	int cardnum = 0, number = 0, rec = 2, choose, selection, selection2, S,C;
	int count = 0, len1 = 0, len2 = 0, len3 = 0, len4 = 0, len5 = 0, pr1 = 0, pr2 = 0, pr3 = 0, pr4 = 0, pr5 = 0,n;
	string str,str1,strold,strnew;
    cout << fixed << showpoint << setprecision(2);
    cout << "\nPlease make a selection:" << endl;
	cout << "1) Choose existing account" << endl;
	cout << "2) Add new account" << endl;
    cout << "3) Quit\n" << endl;
    cin >> selection;
	switch (selection)
		{
		case 1:	{
				PB = fopen("data.txt", "r");
				n = 1;
				while (1)	{
					p = fgets(s, 80, PB);
					if (p == NULL) break;
					cout << n << ") ";
					puts(p);
					n++;
				}
				n = 1;
				cout << "Выберите учетную запись: ";
				cin >> choose;
				ifstream fs("data.txt");
				while (getline(fs, str))	{
					if (n == choose)	{
						ofstream out("choice.txt", ios::trunc);
						out << str;
						out.close();
						break;
					}
					n++;
				}
				fs.close();
				fclose(PB);
				char * tmp = new char[str.length() + 1];
				strcpy(tmp, str.c_str());
				for (int i = 0; i < (str.length() + 1); i++)	{
					if (tmp[i] != ' ' && tmp[i] != '\0')	{
						if (count == 0)	{
							len1++;
						}
						if (count == 1)	{
							len2++;
						}
						if (count == 2)	{
							len3++;
						}
						if (count == 3)	{
							len4++;
						}
						if (count == 4)	{
							len5++;
						}
					}
					else	{
						count++;
					}
				}
				pr1 = len1;
				pr2 = len1 + len2 + 1;
				pr3 = len1 + len2 + len3 + 2;
				pr4 = len1 + len2 + len3 + len4 + 3;
				strncpy(name, tmp, len1);
				strncpy(sname, tmp + pr1 + 1, len2);
				strncpy(num, tmp + pr2 + 1, len3);
				strncpy(balanceS, tmp + pr3 + 1, len4);
				strncpy(balanceC, tmp + pr4 + 1, len5);
				cout << "\nName: ";
				for (int xc = 0; xc < len1; xc++)	{
					cout << name[xc];
				}
				cout << "\nSname: ";
				for (int xc = 0; xc < len2; xc++)	{
					cout << sname[xc];
				}
				cout << "\nPersonal number: ";
				for (int xc = 0; xc < len3; xc++)	{
					cout << num[xc];
				}
				cout << "\nBalance on Savings: ";
				for (int xc = 0; xc < len4; xc++)
				{
					cout << balanceS[xc];
				}
				cout << "\nBalance on Debet: ";
				for (int xc = 0; xc < len5; xc++)	{
					cout << balanceC[xc];
				}
				cout << "\n\n"<<endl;
				S = atoi(balanceS);
				C = atoi(balanceC);
				break;
			}
		case 2:		{
			PB = fopen("data.txt", "a+");
			PB2 = fopen("choice.txt", "w");
			ofstream out("choice.txt", ios::trunc);
			Client **pieces = new Client*[number];
			string name, sname;
			int nu, s, c;
			cout << "Input name: ";
			cin >> name;
			cout << "Input surname: ";
			cin >> sname;
			cout << "Input amount of money on Savings account: ";
			cin >> s;
			cout << "Input amount of money on Checkings account: ";
			cin >> c;
			nu = rand() % (90000000) + 10000000;
			pieces[number] = new Client(name, sname, nu, s, c);
			pieces[number]->write2file(PB);
			pieces[number]->write2file(PB2);
			rec++;
			Arr = (ClientData*)realloc(Arr, rec * sizeof(ClientData));
			pieces[number]->show();
			fclose(PB);
			free(Arr);
			number++;
			S = s;
			C = c;
			break;
			}
		}
	if (selection == 2 || selection == 1)
	{
		savings.SetBalance(S);
		debet.SetBalance(C);
		do	{
			cout << "1) Deposit" << endl;
			cout << "2) Withdraw" << endl;
			cout << "3) Transfer" << endl;
			cout << "4) Print balances" << endl;
			cout << "5) Quit\n" << endl;
			cin >> selection2;
			switch (selection2)
			{
			case 1:	{
				cout << endl << "Please select the account you would like to perform operations on(Savings or Chekings):" << endl;
				cin >> accountChoice;
				cout << endl << "Please enter the amount to be deposited:" << endl;
				cin >> transaction;
				cout << endl;
				deposit(transaction, accountChoice);
				break;
			}
			case 2:	{
				cout << endl << "Please select the account you would like to perform operations on(Savings(S) or Chekings(C)):" << endl;
				cin >> accountChoice;
				cout << endl << "Please enter the amount to be withdrawn:" << endl;
				cin >> transaction;
				cout << endl;
				withdraw(transaction, accountChoice);
				break;
			}
			case 3:	{
				cout << endl << "Please select the account from which you would like to perform operations (Savings(S) or Chekings(C)):" << endl;
				cin >> accountChoice;
				cout << endl << "Please enter the amount to be transfered:" << endl;
				cin >> transaction;
				cout << endl;
				transfer(transaction, accountChoice);
				break;
			}
			case 4:
			{
				printBalances();
				break;
			}
			case 5:
			{
				cout << "Closing program..." << endl;
				break;
			}
			}
		} while (selection2 != 5);
		if (selection == 1)
		{
			len1 = 0, len2 = 0, len3 = 0, len4 = 0, len5 = 0;
			pr1 = 0, pr2 = 0, pr3 = 0, pr4 = 0, pr5 = 0;
			int gbS = savings.GetBalance();
			int gbC = debet.GetBalance();
			int diff = (cnt_digits(gbS) - cnt_digits(S)) + (cnt_digits(gbC) - cnt_digits(C));
			ifstream fs1("choice.txt");
			while (fs1) {
				getline(fs1, str1);
			}
			fs1.close();
			char * tmp1 = new char[str1.length() + 1];
			strcpy(tmp1, str1.c_str());
			count = 0;
			for (int i = 0; i < (str1.length() + 1); i++) {
				if (tmp1[i] != ' ' && tmp1[i] != '\0') {
					if (count == 0) {
						len1++;
					}
					if (count == 1) {
						len2++;
					}
					if (count == 2) {
						len3++;
					}
					if (count == 3) {
						len4++;
					}
					if (count == 4) {
						len5++;
					}
				}
				else {
					count++;
				}
			}
			pr1 = len1;
			pr2 = len1 + len2 + 1;
			pr3 = len1 + len2 + len3 + 2;
			pr4 = len1 + len2 + len3 + len4 + 3;
			char arrs[10], arrc[10];
			_itoa(gbS, arrs, 10);
			_itoa(gbC, arrc, 10);
			strncpy(tmp1 + len1 + len2 + len3 + 3, arrs, cnt_digits(gbS));
			int xxxx = cnt_digits(gbS);
			int xxxx2 = cnt_digits(gbC);
			tmp1[len1 + len2 + len3 + xxxx + 3] = ' ';
			strncpy(tmp1 + len1 + len2 + len3 + xxxx + 4, arrc, cnt_digits(gbC));
			tmp1[len1 + len2 + len3 + xxxx + xxxx2 + 4] = '\0';
			ofstream out("choice.txt", ios::trunc);
			out << tmp1;
			out.close();
		}
	}
    system("pause");
    return 0;
}

