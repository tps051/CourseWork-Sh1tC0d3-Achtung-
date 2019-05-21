#define _CRT_SECURE_NO_WARNINGS
#include "Client.h"
#include <string>
#include <string.h>
Client::Client(string nm, string snm, long int a, int balanceS, int balanceC) {
	chName = nm;
	chSname = snm;
	scoreNum = a;
	balS = balanceS;
	balC = balanceC;
}
Client::~Client() {
	cout << "объект уничтожен" << "\n";
}
void Client::input_name()
{
	cin >> chName;
}
void Client::input_sname()
{
	cin >> chSname;
}
void Client::show() 
{
	cout <<"\n" << chName << " " << chSname << " \nPersonal number: "<< scoreNum << "\nSavings money: " << balS << "\nCheckings money: " << balC << endl;
}
void Client::write2file(FILE *x)
{
	fprintf(x, "%s %s %d %d %d\n", chSname.c_str(), chName.c_str(), scoreNum, balS, balC);
}