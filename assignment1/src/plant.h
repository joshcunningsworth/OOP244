/*
plant.h
Author: Josh
*/
//#pragma once

class Plant{
	char plantname[21];
	char type;
public:
	// member functions
	Plant();
	Plant(const char* name, char sym);
	bool isEmpty()const;
	char symbol()const;
	void display()const;
	bool read();
};

