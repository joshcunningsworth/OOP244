/*
garden.h
Created on: Nov 7, 2014
Author: Josh Cunningham
*/

#include "crop.h"

class Garden{
	int gardenl;
	int gardenw;
	char* gardenmap;
	int cropnum;
	Crop type[20];

public:
	Garden();
	Garden(const char*);
	Garden(int l, int w);
	Garden(const Garden&);
	Garden& operator=(const Garden&);
	~Garden();
	bool isEmpty()const;
	bool isOpen()const;
	Garden& operator+=(const Crop&);
	void display(std::ostream&)const;
	void out(std::ofstream&)const;
	void in(std::ifstream&);
};

std::ostream& operator<<(std::ostream& , const Garden&);

//file operators
std::ofstream& operator<<(std::ofstream&, const Garden&);
std::ifstream& operator>>(std::ifstream&, Garden&);

class DetailedGarden : public Garden{
	char* gardendesc;
public:
	DetailedGarden();
	~DetailedGarden();
	DetailedGarden(const char*,int, int);
	DetailedGarden(const DetailedGarden&);
	DetailedGarden& operator=(const DetailedGarden&);
	bool isEmpty()const;
	void display(std::ostream&)const;
};
