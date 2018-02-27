//============================================================================
// Name        : malloc.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	//void malloc(size_t size);
	//void free(void * address);
	//void realloc(void * address, size_t new_size);


	short big_buff[100000];
	//short * big_buff;
	cout << sizeof (big_buff) << endl;
	cout << big_buff << endl;

	return 0;
}
