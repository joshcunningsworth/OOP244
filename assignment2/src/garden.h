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

public:
	Garden();
	Garden(int l, int w);
	Garden(const Garden&);
	Garden& operator=(const Garden&);
	~Garden();
	bool isEmpty()const;
	Garden& operator+=(const Crop&);
	void display(std::ostream&)const;
};

std::ostream& operator<<(std::ostream& , const Garden&);
