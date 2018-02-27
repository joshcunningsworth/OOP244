/*
Sum.cpp
Author: Josh
 */

#include "Sum.h"
#include <cstring>
#include <iostream>
using namespace std;

Sum::Sum(){
	n = nullptr;
	sum = 0;
	amount = 0;
	total = 0;
}

Sum::Sum(int num){
	n = new int[num];
	sum = num;
	amount = 0;
	total = 0;
}

Sum::Sum(const int *numbers, int length){
	total = 0;
	amount = 0;
	sum = 0;
	sum = length;
	n = new int [length];
	for(int x = 0; x < length; x++){
		*this+=numbers[x];
	}
}

void Sum::display() const{
	for(int x = 0; x < sum ; x++){
		cout << n[x];
		if(x+1 < sum){
			cout << "+";
		}
	}
	cout << "=" << amount << "\n";
}

Sum& Sum::operator+=(int num){
	if(total < sum){
		n[total++] = num;
		amount = amount + num;
	}
	else{
		cout << "No Room for anymore numbers " << num << " has not been added\n";
	}
	return *this;
}

Sum::Sum(Sum& src){
	n = nullptr;
	*this=src;
}

Sum& Sum::operator=(Sum& src){
	if(this != &src){
		sum = src.sum;
		amount = src.amount;
		total = src.total;

		if(n != nullptr){
			delete [] n;
			n = nullptr;
		}

		if(src.n != nullptr){
			n = new int [src.sum];
			for(int x = 0; src.sum < x; x++){
				n[x] = src.n[x];
			}
		}
	}
	return *this;
}
