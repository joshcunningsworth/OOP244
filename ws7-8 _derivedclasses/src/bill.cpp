/*
bill.cpp
Created on: Nov 11, 2014
Author: Josh Cunningham
Description: This program will accept a number of receipts the user enters,
the name of the store and the number of items purchased. The user will then
enter the price of the items. The results will be displayed to the user.
*/

#include <cstring>
#include <iomanip>
#include <iostream>
#include "bill.h"

// bill
Bill::Bill(){
	numpurchased = 0;
	prices = nullptr;
}

Bill::Bill(int n, double p[]){
	numpurchased = n;
	prices = new double [n];
	for(int i = 0; i < n; i++){
		prices[i] = p[i];
	}
}

Bill::~Bill(){
	if(numpurchased != 0 && prices != nullptr){
		delete [] prices;
	}
}

double Bill::total()const{
	double total = 0;
	for(int i = 0; i < numpurchased; i++){
		prices[i] += total;
	}
	return total;
}

bool Bill::isEmpty()const{
	if(numpurchased == 0 && prices == nullptr){
		return true;
	}
	else{
		return false;
	}
}

void Bill::display(std::ostream& os)const{
	if(isEmpty() != true){
		for(int i = 0; i < numpurchased; i++){
			os << prices[i];
		}
	}
}


// receipt
Receipt::Receipt(){
	store[0] = ' ';
	numreceipts = 0;
	pricepurchased = '\0';
	receiptprice = nullptr;
}

void Receipt::set(char n[], int p, double r[]){

	//Bill::set()
	strcpy(store, n);
	pricepurchased = p;
	receiptprice = new double [p];
	if(receiptprice != nullptr){
		for(int i = 0; i < p; i++){
			receiptprice[i] = r[i];
		}
	}
	else{
		*this = Receipt();
	}
}

Receipt::~Receipt(){
	if(receiptprice != nullptr){
		delete [] receiptprice;
	}
}

void Receipt::display(std::ostream& os) const{

	//=Bill::total();
	Bill::display(std::cout);
	double total = 0;
	if(isEmpty() != true){
		os << store << std::endl;
		for(int i = 0; i < pricepurchased; i++){
			os << receiptprice[i] << std::endl;
			total += receiptprice[i];
		}
		os << "Total: " << total << std::endl;
	}
}

bool Receipt::isEmpty() const{
	//Bill::isEmpty();
	if(store[0] == ' '){
		return true;
	}
	else{
		return false;
	}
}


//operators
Bill& Bill::operator=(const Bill& receipt){
	if(this != &receipt){
		numpurchased = receipt.numpurchased;
	}
	if(receipt.prices != nullptr){
		delete [] prices;
		prices = nullptr;
	}
	else{
			prices = nullptr;
		}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Receipt& r){
	r.display(os);
	return os;
}

std::istream& operator>>(std::istream& is, Receipt& r){
	int pricepurchased = 0;
	char store[41];

	std::cout << "Name of store: ";
	is >> store;
	std::cout << "Number of items: ";
	is >> pricepurchased;
	std::cout << std::endl;
	double receiptprice[pricepurchased];
	std::cout << "Prices: " << std::endl;
	for(int i = 0; i < pricepurchased; i++){
		std::cout << "Item " << i+1 << ": ";
		is >> receiptprice[i];
		std::cout << "\n";
	}
	r.set(store, pricepurchased, receiptprice);
	return is;
}
