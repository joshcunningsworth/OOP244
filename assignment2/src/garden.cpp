/*
 * garden.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: Josh
 */

#include <cstring>
#include <iomanip>
#include <iostream>
#include "garden.h"

Garden::Garden(){
	gardenl = 0;
	gardenw = 0;
	cropnum = 0;
	gardenmap = nullptr;
}

Garden::Garden(int l, int w){
	if(gardenl >= 0 && gardenw >= 0){
		gardenl = l;
		gardenw = w;
		gardenmap = new char[l*w];
		for(int x = 0; x < l*w;x++){
			gardenmap[x] = ' ';
		}
	}
	else{
		*this = Garden();
	}
}

Garden::Garden(const Garden& g){
	gardenmap = nullptr;
	*this = g;
}

Garden& Garden::operator=(const Garden& g){
	if(this != &g){
		gardenl = g.gardenl;
		gardenw = g.gardenw;

		if(gardenmap != nullptr){
			delete [] gardenmap;
			gardenmap = nullptr;
		}
		if(g.gardenmap != nullptr){
			gardenmap = new char[strlen(g.gardenmap)];
			strcpy(gardenmap, g.gardenmap);
		}
		else{
			gardenmap = nullptr;
		}
	}
	return *this;
}

Garden::~Garden(){
	if(gardenmap != nullptr){
		delete [] gardenmap;
	}
}

bool Garden::isEmpty()const{
	if(gardenw == 0 && gardenl == 0){
		return true;
	}
	else{
		return false;
	}
}

Garden& Garden::operator+=(const Crop& c){
	if(gardenmap != nullptr){
		c.place(gardenmap, gardenl, gardenw);
		cropnum ++;
	}	
	return *this;
}

void Garden::display(std::ostream& os)const{
	if(isEmpty() != true){
		os << '+';
		for(int y = 0; y < gardenw; y++){
			os << '-';
		}
		os << "+\n";
		for(int x = 0; x < gardenl; x++){
			os << '|';
			for(int y = 0; y < gardenw; y++){
				os << gardenmap[x * gardenw + y];
			}
			os << "|\n";
		}
		os << '+';
		for(int y = 0; y < gardenw; y++){
			os << '-';
		}
		os << "+\n";
	}
}

std::ostream& operator<<(std::ostream& os, const Garden& g){
	g.display(os);
	return os;
}
