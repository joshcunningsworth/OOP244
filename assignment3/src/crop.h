/*
crop.h
Author: Josh
*/
#pragma once;
// including headers
#include "plant.h"
#include "map.h"


class Crop {
	// private varaibles
	int length;
	int width;
	int xpos; // x position
	int ypos; // y position
	Plant p;
public:
	// public member functions
	Crop();
	Crop(const Plant&, int l, int w, int x, int y);
	bool isEmpty() const;
	void display(std::ostream&)const;
	bool read(const Plant&,int,int);
	bool place(char* map,int,int) const;
	void in(std::ifstream&);
	void out(std::ofstream&)const;
};

std::ostream& operator<<(std::ostream&, const Crop&);

//file operators
std::ofstream& operator<<(std::ofstream&, const Crop&);
std::ifstream& operator>>(std::ifstream&, Crop&);
