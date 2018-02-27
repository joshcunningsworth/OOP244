/*
crop.cpp
Author: Josh
*/

#include <cstring>
#include <iomanip>
#include <iostream>
#include "crop.h"

Crop::Crop(){
	length = 0;
	width = 0;
	xpos = 0;
	ypos = 0;
}

Crop::Crop(const Plant& temp, int l, int w, int x, int y){
	if(temp.isEmpty() == false && l <= 20 && w <=30 && x <= 30 && y <= 20){
		length = l;
		width = w;
		xpos = x;
		ypos = y;
		p = temp;
	}
	else{
		*this = Crop();
	}
}

// display for map and cout symbols
void Crop::display(std::ostream& os)const{
	if(isEmpty() != true){
		for(int l = 0; l < length; l++){
			for(int w = 0; w < width; w++){
				os << p.symbol();
			}
			os << '\n';
		}
		p.display(os);
		os << '\n';
	}
}

bool Crop::read(const Plant& temp, int l, int w){
	p = temp;
	for(int n = 0; n <= 1; n++){
		std::cout << "Enter Crop Length:";
		std::cin >> length;
		std::cout << "Enter Crop Width:";
		std::cin >> width;

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
		std::cout << "Enter X Position:";
		std::cin >> xpos;
		std::cout << "Enter Y Position:";
		std::cin >> ypos;

		if(xpos >= 0 && ypos >= 0 && xpos && xpos <= MAPW && ypos <= MAPL){
			return true;
		}
	}
	return true;
}

bool Crop::place(char* map, int poopx, int poopy) const{

	// length and width
	int w = xpos + width - 1;
	int l = ypos + length - 1;
	int n = 0;

	if(map == nullptr){
		return false;
	}

	if(poopx < 0 && poopy < 0 && ypos < 0 && xpos < 0){
		return false;
	}

	if(l > 20 && w > 30){
		return false;
	}

	if(isEmpty() == true){
		return false;
	}

	// nested for loop to place the crops onto the map
	for(int x = 0; x < poopx; x++){
		for(int y = 0; y < poopy; y++){
			if(x >= ypos && x <= l && y >= xpos && y <= w){
				map[n++] = p.symbol();
			}

			else if(map[n++] == '\0'){
				map[n++] = ' ';
			}
		}
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

std::ostream& operator<<(std::ostream& os, const Crop& c){
	if(c.isEmpty() == false){
		return os << "enter x: " << "enter y: " << std::endl;
	}
	else{
		return os;
	}
}
