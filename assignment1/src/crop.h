/*
crap.h
Author: Josh
*/

// including headers
#include "plant.h"
#include "map.h"


class Crop {
	// private varaibles
	int length;
	int width;
	Plant p;
public:
	// public member functions
	Crop();
	Crop(const Plant&, int l, int w);
	bool isEmpty() const;
	void display() const;
	bool read(const Plant&,int,int);
	bool place(char map[MAPL][MAPW],int,int) const;
};
