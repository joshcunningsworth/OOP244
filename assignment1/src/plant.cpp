/*
plant.cpp
Author: Josh
*/

#include "plant.h"
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

Plant::Plant(){
	plantname[0] = '\0';
	type = '\0';
}

// copying plant and plant name
Plant::Plant(const char* name, char sym){
	if(name != nullptr && name[0] != '\0'){
		strncpy (plantname, name, 20);
		plantname[20] = '\0';
		type = sym;
		if(strlen(name) == 0 || strlen(name) > 20){
			*this = Plant();
		}
	}
	else{
		*this = Plant();
	}
}

bool Plant::isEmpty()const{
	if(plantname[0] != '\0' || type != '\0'){
		return false;
	}
	else{
		return true;
	}
}

// character symbol
char Plant::symbol()const{
	return type;
}

// display plant name and the type
void Plant::display()const{
	cout << type << " = " << plantname << " ";
}

// user enters plant symbol and name
bool Plant::read(){
	cout << endl;
	cout << " Plant Symbol: ";
	cin >> type;

	// clear buffer
	cin.clear();
	cin.ignore(2000, '\n');

	cout << " Plant Name: ";
	cin.getline(plantname, 20);
	cout << endl;

	for(int i = 2; plantname[i] != '\0'; i++){
		if(type == '\0' || plantname[i] == '0'){
			return false;
		}
	}
	return true;
}

