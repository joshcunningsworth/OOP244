/*
plant.h
Author: Josh
*/
#pragma once;

class Plant{
	char plantname[21];
	char type;
public:
	// member functions
	Plant();
	Plant(const char* name, char sym);
	bool isEmpty()const;
	char symbol()const;
	bool read();
	const char* plantName()const;
	void display(std::ostream&)const;
	void in(std::ifstream&);
	void out(std::ofstream&)const;
};

std::ostream& operator<<(std::ostream& os, const Plant& tempplant);

bool operator==(const Plant& plant1, const Plant& plant2);

//file operators
std::ofstream& operator<<(std::ofstream&, const Plant&);
std::ifstream& operator>>(std::ifstream&, Plant&);
