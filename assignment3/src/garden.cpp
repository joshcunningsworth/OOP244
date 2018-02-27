/*
 * garden.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: Josh
 */

#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "garden.h"

Garden::Garden(){
	gardenl = 0;
	gardenw = 0;
	cropnum = 0;
	gardenmap = nullptr;
}

Garden::Garden(const char* file){
	std::ifstream fin("file");
	if (fin.is_open()){
			fin >> cropnum;
			fin >> gardenl;
			fin >> gardenw;

			if(gardenl >= 0 && gardenw >= 0){
				gardenmap = new char[gardenl*gardenw];
					for(int x = 0; x < gardenl*gardenw;x++){
						gardenmap[x] = ' ';
					}
			}
			else{
			*this = Garden();
			}
	}
	else{
		*this = Garden();
	}
}

Garden::Garden(int l, int w){
	cropnum = 0;
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
			//delete [] gardenmap;
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
		//delete [] gardenmap;
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

void Garden::in(std::ifstream& ifs){
	ifs >> cropnum >> gardenl >> gardenw;
	if (gardenmap != nullptr){
		//delete[] gardenmap;
		gardenmap = nullptr;
	}
	if (gardenl >= 0 && gardenw >= 0){
		gardenmap = new char[gardenl * gardenw];
		for (int i = 0; i < gardenl * gardenw; i++){
			gardenmap[i] = ' ';
		}
	}else{
		*this = Garden();
	}
	for (int i = 0; i < cropnum; i++){
		type[i].in(ifs);
		type[i].place(gardenmap, gardenl, gardenw);
	}
}

void Garden::out(std::ofstream& ofs)const{
	ofs << cropnum << ' ' << gardenl << ' ' << gardenw << std::endl;

	for(int x = 0; x < cropnum;x++){
		type[x].out(ofs);
	}
}

std::ostream& operator<<(std::ostream& os, const Garden& g){
	g.display(os);
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const Garden& g){
	g.out(ofs);
	return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Garden& g){
	g.in(ifs);
	return ifs;
}

DetailedGarden::DetailedGarden(){
	gardendesc = nullptr;
}

DetailedGarden::~DetailedGarden(){
	if(gardendesc != nullptr){
		//delete [] gardendesc;
	}
}

bool DetailedGarden::isEmpty()const{
	if(gardendesc == nullptr && Garden::isEmpty() == true){
		return true;
	}
	else{
		return false;
	}
}

void DetailedGarden::display(std::ostream& os)const{
	Garden::display(os);
	os << gardendesc << std::endl;
}

DetailedGarden::DetailedGarden(const char* desc, int l, int w){
	gardendesc = nullptr;
	if(gardendesc != nullptr && desc != nullptr){
		gardendesc = new char[strlen(desc)];
		for(int x = 0; x < strlen(desc); x++){
			gardendesc[x] = desc[x];
		}
	}
	else{
		*this = DetailedGarden();
	}

}

DetailedGarden::DetailedGarden(const DetailedGarden& detail){
	gardendesc = nullptr;
	*this = detail;
}

DetailedGarden& DetailedGarden::operator=(const DetailedGarden& detail){
		if(detail.gardendesc != nullptr){
			//delete [] gardendesc;
			gardendesc = nullptr;
		}
		if(detail.gardendesc != nullptr){
			gardendesc = new char[strlen(detail.gardendesc)];
			strcpy(gardendesc, detail.gardendesc);
		}
		else{
			gardendesc = nullptr;
		}
	return *this;
}

