/*
plant.cpp
Author: Josh
*/

#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "plant.h"

Plant::Plant(){
	plantname[0] = '\0';
	type = '\0';
}

// copying plant and plant name
Plant::Plant(const char* name, char sym){
	if(name != nullptr && name[0] != '\0'){
		strncpy (plantname, name, 20);
		plantname[20] = '\0';
		type = sym;
		if(strlen(name) == 0 || strlen(name) > 20){
			*this = Plant();
		}
	}
	else{
		*this = Plant();
	}
}

bool Plant::isEmpty()const{
	if(plantname[0] != '\0' || type != '\0'){
		return false;
	}
	else{
		return true;
	}
}

// character symbol
char Plant::symbol()const{
	return type;
}

// user enters plant symbol and name
bool Plant::read(){
	std::cout << std::endl;
	std::cout << " Plant Symbol: ";
	std::cin >> type;

	// clear buffer
	std::cin.clear();
	std::cin.ignore(2000, '\n');

	std::cout << " Plant Name: ";
	std::cin.getline(plantname, 20);
	std::cout << std::endl;

	for(int i = 2; plantname[i] != '\0'; i++){
		if(type == '\0' || plantname[i] == '0'){
			return false;
		}
	}
	return true;
}

const char* Plant::plantName()const{
	return plantname;
}

// display plant name and the type
void Plant::display(std::ostream& os)const{
	if(this->isEmpty() == false){
		os << plantName() << " - " << ' ';
	}
}

std::ostream& operator<<(std::ostream& os, const Plant& tempplant){
	tempplant.display(os);
	return os;
}

bool operator==(const Plant& plant1, const Plant& plant2){

	if(strcmp(plant1.plantName(), plant2.plantName()) == 0 && plant1.symbol() == plant2.symbol()){
		return true;
	}
	else{
		return false;
	}
}

void Plant::in(std::ifstream& ifs){
	char plant;
	ifs >> plant;
	for(int x = 0; x < 20; x++){
		if((plant >= 'a' && plant <= 'z') || (plant >= 'A' && plant <= 'Z')){
			type = plant;
			break;
		}
	}
	ifs.getline(plantname, 20, '\n');
}

void Plant::out(std::ofstream& ofs)const{
	ofs << type << ' ' << plantname << std::endl;
}

std::ofstream& operator<<(std::ofstream& ofs, const Plant& p){
	p.out(ofs);
	return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, Plant& p){
	p.in(ifs);
	return ifs;
}
