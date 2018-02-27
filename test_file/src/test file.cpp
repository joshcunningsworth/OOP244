//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void isValid(char* ean){
	cout << "EAN =" << ean << endl;
}



int main(int argc, char *argv[]) {

	// argc = argument count
	// argv = argument value

/* sizeof checks amount of bytes
cout << sizeof (int) << endl; // size of int is 4
cout << sizeof (char) << endl; // size of char is 1
cout << sizeof (long*) << endl; // size of long is 8
cout << sizeof (double) << endl; // size of double is
cout << sizeof (long long) << endl; // size of long long is 8
cout << sizeof (void) << endl; // size of void is 1
*/

	//char *pgm = argv[0];
	cout << "argc = " << argc << endl; // prints out argc
	cout << "argv[0] = " << argv[0] << endl; // prints out argv
	for (int i = 0; i < argc; i++){
		cout << "argv["<< i <<"]=" << argv[i] << endl;
		isValid(argv[i]);
	}

	return 0;
}
