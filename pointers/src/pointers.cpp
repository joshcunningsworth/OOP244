#include <iostream>
using namespace std;

int main()
{
	int * pInt = new int;
	*pInt = 10;
	cout << "*pInt: " << *pInt << endl;
	long * pLong = new long;
	*pLong = 90000;
	cout << "*pLong: " << *pLong << endl;

	*pInt = 20;

	cout << "*pInt: " << *pInt << endl;
	cout << "*pLong: " << *pLong << endl;
	delete pLong;
	delete pInt;
	return 0;
}
