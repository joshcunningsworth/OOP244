/*
crap.cpp
Author: Josh
*/

#include <cstring>
#include <iomanip>
#include <iostream>
#include "crop.h"
using namespace std;


Crop::Crop(){
	length = 0;
	width = 0;
}

Crop::Crop(const Plant& temp, int l, int w){
	if(temp.isEmpty() == false && l <= 20 && w <=30){
		length = l;
		width = w;
		p = temp;
	}
	else{
		*this = Crop();
	}
}

bool Crop::read(const Plant& temp,int l,int w){
	p = temp;
	for(int n = 0; n <= 1; n++){
		cout << "Enter Crop Length:";
		cin >> length;
		cout << "Enter Crop Width:";
		cin >> width;

		// returns false if all 0
		if(width == 0 || length == 0){
			length = 0;
			width = 0;
			return false;
		}
		if(width > w && length > l){
			n = 0;
		}
		else{
			// n is index of the plant
			n = 2;
		}
	}
	return true;
}

bool Crop::place(char map[MAPL][MAPW], int poopx, int poopy) const{

	// length and width
	int w = poopx + width;
	int l = poopy + length;
	int xtotal = 0;
	int ytotal = 0;

	cout << poopy << "    " << poopx << endl;

	if(map == nullptr){
		return false;
	}

	if(poopx < 0 || poopy < 0){
		return false;
	}

	if(l > 20 || w > 30){
		cout << l << "   " << w << endl;
		return false;
	}

	if(this -> isEmpty() == true){
		return false;
	}

	// nested for loop to place the crops onto the map
	for(int x = poopy; xtotal < length; x++){
		ytotal = 0;
		for(int y = poopx; ytotal < width; y++){
			map[x][y] = p.symbol();
			cout << x << "   " << y << endl;
			ytotal++;
		}
		xtotal++;
	}

	return true;
}

bool Crop::isEmpty() const{
	if(length == 0 && width == 0 && p.isEmpty() == true){
		return true;
	}
	else{
		return false;
	}
}

// display for map and cout symbols
void Crop::display() const{
	for(int l = 0; l < length; l++){
		for(int w = 0; w < width; w++){
			cout << p.symbol();
		}
		cout << '\n';
	}
	p.display();
	cout << '\n';
}
