#include <iostream>
#include <string>
#include <iomanip>      
#include <stdlib.h>
#include <cstdlib>

#include <map>
#include <malloc.h>
#include <string>
#include <string.h>
using namespace std;

class Client 
{
private:
	string chName; 
	string chSname; 
	long int scoreNum;
	int balS, balC;
public:
	Client(string nm, string snm, long int a, int balanceS, int balanceC); 
	~Client(); 	
	void input_name();
	void input_sname();
	void show();
	void write2file(FILE *x);
};